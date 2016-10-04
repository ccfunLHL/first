#include<bits/stdc++.h>
using namespace std;
int n,m;
const int ief=9999999;
const int maxn=100+10;
vector<pair<int,int> > e[maxn];
int d[maxn],dir[maxn];
void init(){
    for(int i=0;i<maxn;i++){
        e[i].clear();
        d[i]=1e9;
        dir[i]=0;
    }
}

int main()
{
    while(scanf("%d%d",&n,&m))
    {
        init();
        if(n==0&&m==0) break;
        for(int i=0;i<m;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            e[x].push_back(make_pair(y,w));
            e[y].push_back(make_pair(x,w));
        }

            queue<int> q;
            q.push(1);
            d[1]=0;
            while(!q.empty())
            {
                int now=q.front();
                q.pop();
                dir[1]=0;
                for(int i=0;i<e[now].size();i++)
                {
                    int v=e[now][i].first;
                    if(d[v]>d[now]+e[now][i].second)
                    {
                        d[v]=d[now]+e[now][i].second;
                        if(dir[v]==1) continue;
                        dir[v]=0;
                        q.push(v);

                    }

                }

            }
            printf("%d\n",d[n]);


    }

    return 0;
}
