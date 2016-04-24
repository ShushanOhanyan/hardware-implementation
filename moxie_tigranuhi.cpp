#include "core.h"

void cmp(string rA, string rB)
{
	int* regA, regB;
	switch (rA)
	{
		case "$r0":
			regA = &genReg[0];
			break;
		case "$r1":
			regA = &genReg[1];
			break;
		case "$r2":
			regA = &genReg[2];
			break;
		case "$r3":
			regA = &genReg[3];
			break;
		case "$r4":
			regA = &genReg[4];
			break;
		case "$r5":
			regA = &genReg[5];
			break;
		case "$r6":
			regA = &genReg[6];
			break;
		case "$r7":
			regA = &genReg[7];
			break;
		case "$r8":
			regA = &genReg[8];
			break;
		case "$r9":
			regA = &genReg[9];
			break;
		case "$r10":
			regA = &genReg[10];
			break;
		case "$r11":
			regA = &genReg[11];
			break;
		case "$r12":
			regA = &genReg[12];
			break;
		case "$r13":
			regA = &genReg[13];
			break;
		case "0":
			regA = &SpecReg[0];
			break;
		case "1":
			regA = &SpecReg[1];
			break;
		case "2":
			regA = &SpecReg[2];
			break;
		case "3":
			regA = &SpecReg[3];
			break;
		case "4":
			regA = &SpecReg[4];
			break;
		case "5":
			regA = &SpecReg[5];
			break;
		case "6":
			regA = &SpecReg[6];
			break;
		case "7":
			regA = &SpecReg[7];
			break;
		case "8":
			regA = &SpecReg[8];
			break;
		case "9":
			regA = &SpecReg[9];
			break;
		case "$sp":
			regA = &sp;
			break;
		case "$fp": 
			regA = &fp;
			break;
		default: 
			return false;
	}

	switch (rB)
	{
		case "$r0":
			regB = &genReg[0];
			break;
		case "$r1":
			regB = &genReg[1];
			break;
		case "$r2":
			regB = &genReg[2];
			break;
		case "$r3":
			regB = &genReg[3];
			break;
		case "$r4":
			regB = &genReg[4];
			break;
		case "$r5":
			regB = &genReg[5];
			break;
		case "$r6":
			regB = &genReg[6];
			break;
		case "$r7":
			regB = &genReg[7];
			break;
		case "$r8":
			regB = &genReg[8];
			break;
		case "$r9":
			regB = &genReg[9];
			break;
		case "$r10":
			regB = &genReg[10];
			break;
		case "$r11":
			regB = &genReg[11];
			break;
		case "$r12":
			regB = &genReg[12];
			break;
		case "$r13":
			regB = &genReg[13];
			break;
		case "0":
			regB = &SpecReg[0];
			break;
		case "1":
			regB = &SpecReg[1];
			break;
		case "2":
			regB = &SpecReg[2];
			break;
		case "3":
			regB = &SpecReg[3];
			break;
		case "4":
			regB = &SpecReg[4];
			break;
		case "5":
			regB = &SpecReg[5];
			break;
		case "6":
			regB = &SpecReg[6];
			break;
		case "7":
			regB = &SpecReg[7];
			break;
		case "8":
			regB = &SpecReg[8];
			break;
		case "9":
			regB = &SpecReg[9];
			break;
		case "$sp":
			regB = &sp;
			break;
		case "$fp": 
			regB = &fp;
			break;
		default: 
			return false;
	}
	
	int result = *regA - *regB; 
	if(result > 0)
		ssr(0, 1);
	else
		if (result == 0)
			ssr(0, 2);
		else
			ssr(0, 0);
}


int gsr (int index)
{
	assert (index >= 0 && index <= 9);
	return SpecReg[index];
}


void ssr (int index, int value)
{
	assert (index >= 0 && index <= 9);
	SpecReg[index] = value;
}

void nop()
{
	;
}

bool push(string rA, string rB )
{
	int* regA, regB;
	switch (rA)
	{
		case "$r0":
			regA = &genReg[0];
			break;
		case "$r1":
			regA = &genReg[1];
			break;
		case "$r2":
			regA = &genReg[2];
			break;
		case "$r3":
			regA = &genReg[3];
			break;
		case "$r4":
			regA = &genReg[4];
			break;
		case "$r5":
			regA = &genReg[5];
			break;
		case "$r6":
			regA = &genReg[6];
			break;
		case "$r7":
			regA = &genReg[7];
			break;
		case "$r8":
			regA = &genReg[8];
			break;
		case "$r9":
			regA = &genReg[9];
			break;
		case "$r10":
			regA = &genReg[10];
			break;
		case "$r11":
			regA = &genReg[11];
			break;
		case "$r12":
			regA = &genReg[12];
			break;
		case "$r13":
			regA = &genReg[13];
			break;
		case "0":
			regA = &SpecReg[0];
			break;
		case "1":
			regA = &SpecReg[1];
			break;
		case "2":
			regA = &SpecReg[2];
			break;
		case "3":
			regA = &SpecReg[3];
			break;
		case "4":
			regA = &SpecReg[4];
			break;
		case "5":
			regA = &SpecReg[5];
			break;
		case "6":
			regA = &SpecReg[6];
			break;
		case "7":
			regA = &SpecReg[7];
			break;
		case "8":
			regA = &SpecReg[8];
			break;
		case "9":
			regA = &SpecReg[9];
			break;
		case "$sp":
			regA = &sp;
			break;
		case "$fp": 
			regA = &fp;
			break;
		default: 
			return false;
	}

	switch (rB)
	{
		case "$r0":
			regB = &genReg[0];
			break;
		case "$r1":
			regB = &genReg[1];
			break;
		case "$r2":
			regB = &genReg[2];
			break;
		case "$r3":
			regB = &genReg[3];
			break;
		case "$r4":
			regB = &genReg[4];
			break;
		case "$r5":
			regB = &genReg[5];
			break;
		case "$r6":
			regB = &genReg[6];
			break;
		case "$r7":
			regB = &genReg[7];
			break;
		case "$r8":
			regB = &genReg[8];
			break;
		case "$r9":
			regB = &genReg[9];
			break;
		case "$r10":
			regB = &genReg[10];
			break;
		case "$r11":
			regB = &genReg[11];
			break;
		case "$r12":
			regB = &genReg[12];
			break;
		case "$r13":
			regB = &genReg[13];
			break;
		case "0":
			regB = &SpecReg[0];
			break;
		case "1":
			regB = &SpecReg[1];
			break;
		case "2":
			regB = &SpecReg[2];
			break;
		case "3":
			regB = &SpecReg[3];
			break;
		case "4":
			regB = &SpecReg[4];
			break;
		case "5":
			regB = &SpecReg[5];
			break;
		case "6":
			regB = &SpecReg[6];
			break;
		case "7":
			regB = &SpecReg[7];
			break;
		case "8":
			regB = &SpecReg[8];
			break;
		case "9":
			regB = &SpecReg[9];
			break;
		case "$sp":
			regB = &sp;
			break;
		case "$fp": 
			regB = &fp;
			break;
		default: 
			return false;
	}

	int* stck = (int*) *regA;
	stck--;
	*stck = regB;
	*regA = *stck;
	return true;
}

bool pop (string rA, string rB)
{
	int* regA, regB;
	switch (rA)
	{
		case "$r0":
			regA = &genReg[0];
			break;
		case "$r1":
			regA = &genReg[1];
			break;
		case "$r2":
			regA = &genReg[2];
			break;
		case "$r3":
			regA = &genReg[3];
			break;
		case "$r4":
			regA = &genReg[4];
			break;
		case "$r5":
			regA = &genReg[5];
			break;
		case "$r6":
			regA = &genReg[6];
			break;
		case "$r7":
			regA = &genReg[7];
			break;
		case "$r8":
			regA = &genReg[8];
			break;
		case "$r9":
			regA = &genReg[9];
			break;
		case "$r10":
			regA = &genReg[10];
			break;
		case "$r11":
			regA = &genReg[11];
			break;
		case "$r12":
			regA = &genReg[12];
			break;
		case "$r13":
			regA = &genReg[13];
			break;
		case "0":
			regA = &SpecReg[0];
			break;
		case "1":
			regA = &SpecReg[1];
			break;
		case "2":
			regA = &SpecReg[2];
			break;
		case "3":
			regA = &SpecReg[3];
			break;
		case "4":
			regA = &SpecReg[4];
			break;
		case "5":
			regA = &SpecReg[5];
			break;
		case "6":
			regA = &SpecReg[6];
			break;
		case "7":
			regA = &SpecReg[7];
			break;
		case "8":
			regA = &SpecReg[8];
			break;
		case "9":
			regA = &SpecReg[9];
			break;
		case "$sp":
			regA = &sp;
			break;
		case "$fp": 
			regA = &fp;
			break;
		default: 
			return false;
	}

	switch (rB)
	{
		case "$r0":
			regB = &genReg[0];
			break;
		case "$r1":
			regB = &genReg[1];
			break;
		case "$r2":
			regB = &genReg[2];
			break;
		case "$r3":
			regB = &genReg[3];
			break;
		case "$r4":
			regB = &genReg[4];
			break;
		case "$r5":
			regB = &genReg[5];
			break;
		case "$r6":
			regB = &genReg[6];
			break;
		case "$r7":
			regB = &genReg[7];
			break;
		case "$r8":
			regB = &genReg[8];
			break;
		case "$r9":
			regB = &genReg[9];
			break;
		case "$r10":
			regB = &genReg[10];
			break;
		case "$r11":
			regB = &genReg[11];
			break;
		case "$r12":
			regB = &genReg[12];
			break;
		case "$r13":
			regB = &genReg[13];
			break;
		case "0":
			regB = &SpecReg[0];
			break;
		case "1":
			regB = &SpecReg[1];
			break;
		case "2":
			regB = &SpecReg[2];
			break;
		case "3":
			regB = &SpecReg[3];
			break;
		case "4":
			regB = &SpecReg[4];
			break;
		case "5":
			regB = &SpecReg[5];
			break;
		case "6":
			regB = &SpecReg[6];
			break;
		case "7":
			regB = &SpecReg[7];
			break;
		case "8":
			regB = &SpecReg[8];
			break;
		case "9":
			regB = &SpecReg[9];
			break;
		case "$sp":
			regB = &sp;
			break;
		case "$fp": 
			regB = &fp;
			break;
		default: 
			return false;
	}

	int* stckPtr = (int*) *regB;
	*regA = *stckPtr;
	stckPtr++;
	*regB = *stckPtr;
	return true;
}


void ret ()
{
	jmp (SpecReg[5]); // ????

}
