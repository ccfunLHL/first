//============================================================================
// Name        : HDU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Trie
{
    int next[210*500][128],fail[210*500],end[210*500];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 128;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]] == -1)
                next[now][s[i]] = newnode();
            now=next[now][s[i]];
        }
        end[now]=id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 128;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 128;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    bool used[510];
    bool query(char buf[],int n,int id)
    {
        int len = strlen(buf);
        int now = root;
        memset(used,false,sizeof(used));
        bool flag = false;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                {
                    used[end[temp]] = true;
                    flag = true;
                }
                temp = fail[temp];
            }
        }
        if(!flag)return false;
        printf("web %d:",id);
        for(int i = 1;i <= n;i++)
            if(used[i])
                printf(" %d",i);
        printf("\n");
        return true;
    }
};
char buf[10010];
Trie ac;
int main()
{
    int n,m;
    while(scanf("%d",&n) != EOF)
    {
        ac.init();		//建树跟 
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",buf);	//输入要查询的字符串 
            ac.insert(buf,i);		//插入字符串 
        }
        ac.build();		// 建树 
        int ans = 0;
        scanf("%d",&m);	//大串的个数 
        for(int i = 1;i <= m;i++)
        {
            scanf("%s",buf); 	//大串 
            if(ac.query(buf,n,i))	//在大串中找n个小串 
                ans++;
        }
        printf("total: %d\n",ans);
    }
    return 0;
}
