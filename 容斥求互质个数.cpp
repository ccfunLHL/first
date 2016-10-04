/*
题目描述： 给定你一个数n，请你统计出在[a,b]这个区间中和n互质的数的个数。
			两个数互质当且仅当他们除了1之外没有其他的公共因子或者他们最大的公共因子是1。1和任何数是互素的。
输入: 第一行输入一个整数T（1 <= T <= 100），表示T组测试数据。
	接下来T行，每行3个整数a，b，n（1 <= a <=b <=10^15, 1<= n <= 10^9），用空格隔开。
输出: 输出一个整数表示和n互质的数的个数。
样例:	
	输入 
		2
		1 10 2
		3 10 5
	输出 
		5
		6
*/ 


#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1000000;

int p[maxn];

int is_p(ll n)
{
	int tot=0;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			p[tot++]=i;
			while(n%i==0) n/=i;
		}
		 
	}
	if(n>1) p[tot++]=n;
	
	return tot;
	
	
}
ll get(ll num,ll n)
{
	ll ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		ll temp=1,flag=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				flag++;
				temp*=p[j];
			}
		}
		if(flag&1) ans+=num/temp;
		else ans-=num/temp;
	}
	return ans;
}
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,n;
		cin>>a>>b>>n;
		int tot=is_p(n);
		
		cout<<(b-get(b,tot))-(a-1-get(a-1,tot))<<endl;
		 
	}

	
	return 0;
}
