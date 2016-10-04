#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int maxn=1000+10;
int s[maxn];
int n;
int low(int t)
{
	return t&(-t);
}
void update(int i,int x)
{
    while(i<=n)
    {
        s[i]+=x;
        i+=low(i);
    }
}

int sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=s[i];
        i-=low(i);
    }
    return sum;

}
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        update(i,x);
    }
    int q;
    while(~scanf("%d",&q))
    printf("%d\n",sum(q));


    return 0;
}
