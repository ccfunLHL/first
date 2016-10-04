#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7; 
const int maxn=105;
int n;
struct mat{
	ll a[maxn][maxn];
}dam;
mat operator *(mat a,mat b)
{
	mat res;
	ll x;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		x=0;
		for(int k=0;k<n;k++)
		x+=(a.a[i][k]*b.a[k][j])%mod;
		res.a[i][j]=x%mod;
	}
	return res;
}
void fun()
{
	for(int i=0;i<maxn;i++)
	dam.a[i][i]=1;
}
mat pow_dan(mat a,ll n)
{
	mat ret=dam;
	while(n)
	{
		if(n&1)
		{
			n--;
			ret=ret*a;
		}
		n>>=1;
		a=a*a;
	}
	return ret;
} 
int main()
{
	ll x;
	fun();
	scanf("%d%lld",&n,&x);
	mat a;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		scanf("%lld",&a.a[i][j]);
	a=pow_dan(a,x);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%lld ",a.a[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
