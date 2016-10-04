/*
��Ŀ������ ������һ����n������ͳ�Ƴ���[a,b]��������к�n���ʵ����ĸ�����
			���������ʵ��ҽ������ǳ���1֮��û�������Ĺ������ӻ����������Ĺ���������1��1���κ����ǻ��صġ�
����: ��һ������һ������T��1 <= T <= 100������ʾT��������ݡ�
	������T�У�ÿ��3������a��b��n��1 <= a <=b <=10^15, 1<= n <= 10^9�����ÿո������
���: ���һ��������ʾ��n���ʵ����ĸ�����
����:	
	���� 
		2
		1 10 2
		3 10 5
	��� 
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
