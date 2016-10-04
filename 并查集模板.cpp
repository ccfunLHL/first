/*
某城市有n个人，现在给定关于n个人的m条信息，m条信息是两个人在同一个小区，根据所给信息，判断这个城市最多可能有多少个小区。n个人编号为1~n。
输入
多组输入。
每组第一行有两个整数n，m（2 <= n <= 50000， 0 <= m <= n/2）。
接下来m行，每行两个整数a，b，表示a和b在同一个小区。
输出
根据所给信息，输出这个城市最多可能有多少个小区。
示例输入
5 2
1 2
3 4
示例输出
3


*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
const int maxn=50000+100;
int pa[maxn];
int rank[maxn];
struct bingchaji{
    void make_set(int x)
    {
        pa[x]=x;
        rank[x]=0;
    }
    int find_set(int x)
    {
        if(x!=pa[x])
            pa[x] = find_set(pa[x]);
        return pa[x];
    }
    void union_set(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if(rank[x]>rank[y])
            pa[y]=x;
        else {
            pa[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }
};
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        bingchaji pp;
        for(int i=1;i<=n;i++)
            pp.make_set(i);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            pp.union_set(a,b);
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(pa[i]==i) sum++;
        }
        printf("%d\n",sum);
    }




    return 0;
}
