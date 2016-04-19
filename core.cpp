#include "MemoryBus.h"
#include "IDE.h"
#include "core.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>
#include <signal.h>
#include <algorithm> 
#include "CommandStruct.h"
#include <map>
#include "Common.h"
using namespace std;

Common common;
int core::IP = 0;
// points at the top of the stack, stack stard from 3000th byte
int core::SP = common.stackBegan;
// points at the end of the stack,stack end in 3300th byte
int core::BP = common.stackEnd;
std::map<std::string,int> core::genReg = getRegs();
		
bool core::mov(int* from, int* to)
{
/*		
 * 
*/
}

void core::add(string r1, string r2)
{
	genReg[r1] = genReg[r1] + genReg[r2];	
}

void core::sub(string r1, string r2)
{
	genReg[r1] = genReg[r1] - genReg[r2];	
}



//push value to stack
bool core::push(int* addres)
{			
	MemoryBus memBus;	
	int Number = *addres;//number to convert int a string
	string Result;//string which will contain the result
	stringstream convert; // stringstream used for the conversion
	convert << Number;//add the value of Number to the characters in the stream
	Result = ';' + convert.str();//set Result to the content of the stream
	Result.push_back(';');
		
	int size = Result.size();	
	
	const char * charResult = Result.c_str();

	//lock bus
	memBus.Lock();	

	//write to stack
	memBus.Write((void*)charResult,SP,size);
	//enlarge stack pointer
	SP = SP + size;	
	
	if(SP == BP)
	{
		//dump stack, when it is overflow
		//and unlock memory Bus
		SP = common.stackBegan;
		memBus.Unlock();
		cout<<"stack overflow"<<endl;
		return false;
	}
	
	//unlock bus
	memBus.Unlock();
		
	return true;
	
}

int core::pop()
{		
   MemoryBus memBus;   
   SP = SP - 2;
   int ip = SP;
   char* ch = new char[2];
   string result;
   //read SP from memory  
	while(1)
	{	
		memBus.Read(ip,(void*)ch,1);
		if(*ch == ';')
		break;
		result.push_back(*ch);
		ip--;
	}	
		
	std::reverse(result.begin(),result.end());
	int value = atoi(result.c_str());
	
	return value;   
}

bool core::call(int addres)
{
	push(&IP);
	IP = addres;

	return true;
}

bool core::ret()
{
	IP = pop();
	
	return true;
}

bool core::in()
{
	
}
//arguments are show ` whom and what to send
bool core::out(string whosCommand, Command command)
{
	
	if(whosCommand == "hdd")
	{
		IDE ide;
		ide.Out(command);
	}
	
	return true;	
}

	
std::map<std::string,int>  core::getRegs()
{
	genReg["$r0"] = 0;
	genReg["$r1"] = 0;
	genReg["$r2"] = 0;
	genReg["$r3"] = 0;
	genReg["$r4"] = 0;
	genReg["$r5"] = 0;
	genReg["$r6"] = 0;
	genReg["$r7"] = 0;
	genReg["$r8"] = 0;
	genReg["$r9"] = 0;
	genReg["$r10"] = 0;
	genReg["$r11"] = 0;
	genReg["$r12"] = 0;
	genReg["$r13"] = 0;
	return genReg;
}

void core::Run()
{	
	MemoryBus memBus;
	
	//3000 byte for code segment
	int memForCode = common.codeSegmentSize;
	//operation and arguments saves in toDo,
	vector<string> toDo;
	while(memForCode)
	{		
		string get;
		//read byet from memorey to ch
		char* ch = new char[2];
		while(*ch != ',' || *ch != ';')
		{			
			//read for memory
			memBus.Read(IP,(void*)ch,1);	
					
			if(*ch == ',' || *ch == ';')
			{
				IP += 1;
				break;
			}		
			
			get.push_back(*ch);		
			IP += 1;		
		}			
		
		if(*ch == ',')
		{			
			//get operator
			toDo.push_back(get);
		}
		
		if(*ch == ';')
		{		
			//end of comand
			toDo.push_back(get);			
			
			//check wich comand it is
			if(toDo[0] == "push")
			{
				std::string myString = toDo[1];
				int value = atoi(myString.c_str());
				push(&value);
			}		
			
			if(toDo[0] == "in")
			{
				in();
			}
						
			if(toDo[0] == "pop")
			{
				pop();
			}
			
			if(toDo[0] == "call")
			{
				std::string myString = toDo[1];
				int value = atoi(myString.c_str());				
				call(value);
			}
			
			if(toDo[0] == "ret")
			{
				ret();
			}
				
			if(toDo[0] == "out")
			{				
				std::string myString = toDo[1]; //HDD comand				
				std::string myString2 = toDo[2]; 				 
				long value2 = atoi(myString2.c_str());	//th byte from 
				std::string myString3 = toDo[3]; 
				long value3 = atoi(myString3.c_str()); //th byte to				 
				char* h = new char[2];
				string s;
				int ip = value2;
				 				 
				while(*h != ',' ) //from given byte read,,for count a size
				{			
					//read for memory
					memBus.Read(ip,(void*)h,1);							
					if(*h == ',' )
					{
						break;
					}		
					
					s.push_back(*h);		
										
					ip++;
				}		
				 
				 int size; 
				 
				 //get struct for sending
				Command command;
				string cmd = "hdd";
				 if(myString == "write")
				 {					 
					size = s.size();			
					command.str = 'w';
					value2 = (int)value2;
					command.it = value2;
					command.lg = value3;
					command.size = size;
				 }
				 
				 if(myString == "read")
				 { 
         			size = atoi(toDo[4].c_str());				 
					command.str = 'r';
					value3 = (int)value3;
					command.it = value3;
					command.lg = value2;
					command.size = size;
				 }
				 
				 if(myString == "copy")
				 { 
					size = atoi(toDo[4].c_str());					
					command.str = 'c';
					command.lg = value2;
					command.lgForCpy = value3;
					command.size = size;
				 }
				 
				out(cmd, command);
			}
				
			toDo.clear();
		}		
		
		memForCode--;
	}
	
	
}


//out,write,1,566;(from,to)
//out,read,265,2,59;(from,to,size)
//out,copy,200,300,9;(long from,long to,int size)
//push,15;
//pop;
//call,16(16 is addres)
//ret;




