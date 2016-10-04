//poj 3468 

#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100000+10;
ll sum[maxn<<2];
ll mark[maxn<<2];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void pushup(int rt)
{
   	 sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdawn(int rt,int len)
{
	    if(mark[rt])
	    {
	        mark[rt<<1]+=mark[rt];
	        mark[rt<<1|1]+=mark[rt];
	
	        sum[rt<<1]+=mark[rt]*(len-(len>>1));
	        sum[rt<<1|1]+=mark[rt]*(len>>1);
	        mark[rt]=0;
	    }
}
void build(int l,int r,int rt)
{
        mark[rt]=0;
        if(l==r){
            scanf("%lld",&sum[rt]);
            return ;
        }
        int m=(r+l)>>1;
        build(lson);
        build(rson);
        pushup(rt);

}
void update(int L,int R,ll c,int l,int r,int rt)
{
	    if(l>=L && r<=R){
	        mark[rt]+=c;
	        sum[rt]+=c*(r-l+1);
	        return ;
	    }
	    
	    pushdawn(rt,r-l+1);
	    int m=(l+r)>>1;
	    if(m>=L) update(L,R,c,lson);
	    if(m<R) update(L,R,c,rson);
	    pushup(rt);
}
ll query(int L,int R,int l,int r,int rt)
{
	    if(l>=L && r<=R) return sum[rt];
	    pushdawn(rt,r-l+1);
	    int m=(r+l)>>1;
	    ll res=0;
	    if(m>=L) res+=query(L,R,lson);
	    if(m<R) res+=query(L,R,rson);
	    return res;
}


int main()
{
	    int n,q;
	    scanf("%d%d",&n,&q);
	    build(1,n,1);
	    while(q--) 
	    {
	    	getchar();
	        char op;
	        int a,b;
	        scanf("%c %d %d",&op,&a,&b);
	        if(op=='Q') printf("%lld\n",query(a,b,1,n,1));
	        else {
	            ll c;
	            scanf("%lld",&c);
	            update(a,b,c,1,n,1);
	        }
	    }




    return 0;
}
