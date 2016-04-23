#ifndef _CORE
#define _CORE
#include "MemoryBus.h"
#include "CommandStruct.h"
#include "IDE.h"
#include <string>
#include <map>
class core
{ 
	private:
		
		IDE ide;
		//stores the address of the array of pointers, that points to interrupt handlerer functions
		int* IDTR;
		// points at the end of the stack
		static int BP;
		// points at the top of the stack
		static int SP;
		// stores the address of the next instruction to be executed
		static int IP;


		static std::map<std::string,int> 	genReg;
		static int SpecReg[10];

		
		//move from first argument,to second
		bool mov(int* from, int* to);
		//push to stack
		static bool push(int*);
		//pop from stack
		static int pop();
		// implements a subroutine return mechanism
		static bool ret();
		//implement a subroutine call and return
		static bool call(int);
		bool lidtr();
		//Input to HDD		
		static bool in();
		//output from HDD
		static bool out(std::string whosCommand,Command command);
	    static std::map<std::string,int>  getRegs();
		static void add(std::string r1, std::string r2); 
		static void sub(std::string r1, std::string r2); 
	public:
		//strat to exequte code from memory
		static void Run();	

};

#endif

