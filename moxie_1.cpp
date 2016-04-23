void stb(int ra, int rb)
{
	*((char*)ra)=(char)rb;
}

void stl(int ra,int rb)
{
	*((int*)ra)=rb;
}

void sts(int ra, int rb)
{
	*((short*)ra)=(int)rb;
}
