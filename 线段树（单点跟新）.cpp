/*
线段树功能:update:单点增减 query:区间求和 
*/ 

#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
const int maxn=10000+10;
int sum[maxn*maxn];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
//跟新求区间和 
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
//建树
void build(int l,int r,int rt)
{
    if(l==r){
        scanf("%d",&sum[rt]);
        return ;
    }
    int m=(r+l)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
//单点跟新
//点加 
void update(int p,int add,int l,int r,int rt)
{
    if(l==r){
        sum[rt]+=add;
        return ;
    }
    int m=(r+l)>>1;
    if(p<=m) update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);

}



//查询区间内的最大值
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    int m=(r+l)>>1;
    int ret=0;						//若求最值改为 
    if(L<=m) ret+=query(L,R,lson);	//ret=max(ret,query(L,R,lson)); 
    if(R>m) ret+=query(L,R,rson);	//ret=max(ret,query(L,R,son));
    return ret;

}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        build(1,n,1);
        char op[10];
        while(~scanf("%s",op))
        {
            if(op[0]=='E') break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(op[0]=='Q') printf("%d\n",query(a,b,1,n,1));
            else if(op[0]=='S') update(a,b,1,n,1);
            else update(a,-b,1,n,1);
        }



    }





    return 0;
}
