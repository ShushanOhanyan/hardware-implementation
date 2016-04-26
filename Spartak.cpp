void stb(string ra, string rb)
{
	int rara = genReg[0];
	int rbrb = genReg[1];
	
	*((int*)rara)=(char)rbrb;
}

void stl(string ra,string rb)
{
	int rara = genReg[0];
	int rbrb = genReg[1];
	*((int*)rara)=rbrb;
}

void sts(string ra, string rb)
{
	int rara = genReg[0];
	int rbrb = genReg[1];
	*((int*)ra)=(short)rbrb;
}

void stab(string ra, int rb)
{
	int rara = genReg[0];
	*((int*)rb) = (char)rara;
}

void stal(string ra, int rb)
{
	int rara = genReg[0];
	*((int*)rb) = rara;
}

void stas(string ra, int rb)
{
	int rara = genReg[0];
	*((int*)rb) = short(rara)
}

//void stob(string ra,)
























