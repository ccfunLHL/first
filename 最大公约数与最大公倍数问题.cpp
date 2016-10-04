#include<stdio.h>
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	if(y%x!=0){
		printf("0\n");
		return 0;
		}
	int sum=0;
	for(int j=1;j*x<=y;j++)
	{
		int t=j*x;
		if(y%t==0){
			int p=x*y/t;

			if(gcd(t,p)==x) sum++; 
		}
	}
	printf("%d\n",sum);
	
	
	
	return 0;
}
