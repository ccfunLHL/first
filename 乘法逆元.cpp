#include<stdio.h>
#include<algorithm>
using namespace std;
const int mod=9973;
int q_pow(int n,int m)
{
    int ans=1;
    while(m>0)
    {
        if(m&1) ans=ans*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ans;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(a%mod)*(q_pow(b%mod,mod-2)%mod)%mod);
    }




    return 0;
}
