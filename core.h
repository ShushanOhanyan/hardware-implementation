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

                //logical operations
	 // underscores have been added intentionally
		void and_(int& ,int );
		void or_(int& ,int );
		void xor_(int& ,int);
		void ashl(int& ,int );
		void ashr(int& ,int );
		void lshr(int& ,int);
		void sex_b(int& ,int);
		void sex_s(int& ,int);
		void not_(int& ,int );
		
		
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
				static bool call(int);
		//Input to HDD		
		static bool in();
		//output from HDD
		static bool out(std::string whosCommand,Command command);
	    static std::map<std::string,int>  getRegs();
		static void add(std::string r1, std::string r2); 
		static void sub(std::string r1, std::string r2); 
		static void zex_s(std::string r1, std::string r2);
		static void zex_b(std::string r1, std::string r2); 
				bool ld_b(std::string rA, std::string rB);
		bool ld_l(std::string rA, std::string rB);
		bool ld_s(std::strng rA, std::string rB);
		bool lda_b(std::string rA , char* opadress);
		bool lda_l(std::string rA,  char* opadress);
		bool lda_s(std::string rA,  char* opadress);
		bool ldi_b(std::string rA,  char* opadress);
		bool ldi_l(std::string rA,  char* opadress);
		bool ldi_s(std::string rA,  char* opadress);
		bool ldo_b(std::string rA,  char* opadress);
		bool ldo_l(std::string rA,  char* opadress);
	
	public:
		//strat to exequte code from memory
		static void Run();	

};

#endif

