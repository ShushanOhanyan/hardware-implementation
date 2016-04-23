void and_(int& rA,int rB)
{
   rA=rA&rB;
}
void or_(int& rA,int rB)
{
   rA=rA|rB;
}
void xor_(int& rA,int rB)
{
   rA=rA^rB;
}
void ashl(int& rA,int rB)
{
rA=rA<<rB;
}

void ashr(int& rA,int rB)
{
rA=rA>>rB;
}

void lshr(int& rA,int rB)
{
  int mask=((1<<31)>>rB)<<1;
  rA=(rA>>rB)&(~mask);
}
void sex_b(int& rA,int rB)
{
 rA=(rB<<24)>>24;
}
void sex_s(int& rA,int rB)
{
rA=(rB<<16)>>16;
}

void not_(int& rA,int rB)
{
  rA=!rB;
}
