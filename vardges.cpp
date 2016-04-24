#include "core.h"

void core::zex_b(std::string r1, std::string r2)
{
	genReg[r1] = genReg[r2] & 0xff;
}

void core::zex_s(std::string r1, std::string r2)
{
	genReg[r1] = genReg[r2] & 0xffff;
}
