#include<bits/stdc++.h>
using namespace std;
int next[100];
struct KMP{
	void get_next(string s)
	{
		next[0]=s.size();
		int i=0,j=-1;
		while(i!=next[0]-1)
		{
			if(j==-1||s[i]==s[j])
			{
				++i;
				++j;
				next[i]=j;
			}
			else {
				j=next[j];
			}	
		}
	}
	
	int kmp(string t,string s)
	{
		get_next(s);
		int i=0,j=0;
		while(i<t.size()&&j<s.size())
		{
			if(j==0 || t[i]==s[j])
			{
				i++;
				j++;
			}
			else {
				j=next[j];
			}
		}
		if(j==s.size()) printf("%d",i-j+1);
		else printf("-1");
	}
}KMP;
int main()
{
		
	string t,s;
	cin>>t>>s;
	KMP.kmp(t,s);

	
	
	
	
	return 0;
} 
