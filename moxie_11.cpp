void and_(string r1, string r2)
{
genReg[r1] = genReg[r1] & genReg[r2]; 
}
void or_(string r1, string r2)
{
   genReg[r1]=genReg[r1]|genReg[r2];
}
void xor_(string r1, string r2)
{
   genReg[r1]=genReg[r1]^genReg[r2];
}
void ashl(string r1, string r2)
{
genReg[r1]=genReg[r1]<<genReg[r2];
}

void ashr(string r1, string r2)
{
genReg[r1]=genReg[r1]>>genReg[r2];
}

void lshr(string r1, string r2)
{
  int mask=((1<<31)>>genReg[r2])<<1;
  genReg[r1]=(genReg[r1]>>genReg[r2])&(~mask);
}
void sex_b(string r1, string r2)
{
genReg[r1]=(genReg[r2]<<24)>>24;
}
void sex_s(string r1, string r2)
{
genReg[r1]=(genReg[r2]<<16)>>16;
}

void not_(string r1, string r2)
{
genReg[r1]=!(genReg[r2]);
}
