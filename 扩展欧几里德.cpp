#include<stdio.h>
int extgcd(int a,int b,int &x,int &y)
{
	int d=a;
	if(b!=0)
	{
		extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else {
		x=1;
		y=0;
	}
	return d;
}
int main()
{
	
	
	
	
	return 0;
} 
