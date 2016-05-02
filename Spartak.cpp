void stb(string ra, string rb)
{
	int rara = genReg[ra];
	int rbrb = genReg[rb];
	
	*((int*)rara)=(char)rbrb;
}

void stl(string ra,string rb)
{
	int rara = genReg[ra];
	int rbrb = genReg[rb];
	*((int*)rara)=rbrb;
}

void sts(string ra, string rb)
{
	int rara = genReg[ra];
	int rbrb = genReg[rb];
	*((int*)ra)=(short)rbrb;
}

void stab(string ra, int rb)
{
	int rara = genReg[ra];
	*((int*)rb) = (char)rara;
}

void stal(string ra, int rb)
{
	int rara = genReg[ra];
	*((int*)rb) = rara;
}

void stas(string ra, int rb)
{
	int rara = genReg[ra];
	*((int*)rb) = short(rara)
}

//void stob(string ra,)
























