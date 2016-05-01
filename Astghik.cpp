///load functions


#include "core.h"

using namespace std;
 
 MemoryBus memBus; 
 
bool core::ld_b (std::string rA ,std::string rB)
{
		memBus.Read(genReg[rB] , (void*)&genReg[rA] , 1);
		return true;
};
	
bool core::ld_l(std::string rA ,std::string rB)
{
		memBus.Read(genReg[rB] , (void*)&genReg[rA] , 4);
		return true;
};

bool core::ld_s (std::string rA ,std::string rB)
{
		memBus.Read(genReg[rB] ,(void*)&genReg[rA] , 2);
		return true;
}


bool core::lda_b (std::string rA , char* opadress)
{
		//memBUs.Read((char)IP+2,(void*)&genReg[rA] , 1);
		memBus.Read(int(opadress + 2), (void*)&genReg[rA] , 1);
		genReg[rA] = genReg[rA]&0xff ;
		return true;
}


bool core::lda_l (std::string rA  , char* opadress)
{
		                //memBus.Read((char)IP +2, (void*)&genReg[rA], 4);
	memBus.Read(int(opadress+2), (void*)&genReg[rA] ,2 );
	genReg[rA] = genReg[rA]&0xffff ;
	return true;
}

////????//////////////

bool core::ldi_b(std::string rA , char* opadress)
{
	int* ad = (int*)(opadress+2 );
	genReg[rA] = *ad; 
	return true;
}

bool core::ldi_s(std::string rA , char* opadress)
{
	int* ad = (int*)((short*)(opadress)+2);
	genReg[rA] = *ad; 
	return true;
}

bool core::ldi_l(std::string rA , char* opadress)
{
	int* ad = (int*)(opadress+2 );
	genReg[rA] = *ad; 
	return true;
}
