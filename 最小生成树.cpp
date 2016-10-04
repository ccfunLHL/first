#include<bits/stdc++.h>
#define maxx 100000000
using namespace std;
int m,n,f[105];
struct di
{
    int start;
    int over;
    int cost;
}dis[1000];
int cmp(di x,di y)
{
    return x.cost<y.cost;
}
int findd(int x)
{
    if(x!=f[x])
        f[x]=findd(f[x]);
    return f[x];
}
int krus()
{
    int k=0,s=0,x,y;
    for(int i=1;i<=m;i++ )
    {
        x=findd(dis[i].start);
        y=findd(dis[i].over);
        if(x!=y)
        {
            s+=dis[i].cost;
            k++;
            if(k==n-1)
                break;
            f[x]=y;
        }
    }
    if(k!=n-1)
        s=-1;
    return s;
}
int main()
{
    while(scanf("%d%d",&m,&n)&&m)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&dis[i].start,&dis[i].over,&dis[i].cost);
        }
        for(int i=1;i<=n;i++)
            f[i]=i;
        sort(dis+1,dis+m+1,cmp);

        int ans=krus();
        if(ans==-1)
            printf("?\n");
        else
            printf("%d\n",ans);

    }
    return 0;
}
