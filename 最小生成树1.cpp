#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100000;

int n,m;
struct p{
    int u,v,s;
}p[maxn];
int fa[maxn];

bool cmp(struct p a,struct p b)
{
    return a.s<b.s;
}
void make_set()
{
    for(int i=0;i<m;i++)
    {
        fa[i]=i;

    }
}
int find_set(int x)
{
    if(x!=fa[x])
    {
        fa[x]=find_set(fa[x]);
    }
    return fa[x];
}


int main()
{

    while(scanf("%d%d",&n,&m)==2)
	{
	 
    make_set();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].s);
    }
    sort(p,p+m,cmp);

    int q=0;
    int z=0;
    int sum=0;
    while(q<=n)
    {
        int x=find_set(p[z].v);
        int y=find_set(p[z].u);
        if(x!=y)
        {
            fa[x]=y;
            sum+=p[z].s;
            q++;
        }
        z++;

    }
    for(int i=1;i<m;i++)
    {
    	if(fa[i]!= fa[1]) sum=-1; 
    }
    if(sum==-1) printf("?\n");
    else 
    	printf("%d\n",sum);

	}

    return 0;
}
