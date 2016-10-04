#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxn=26;
typedef struct Trie{
    int v;
    Trie *next[maxn];
}Trie;

Trie root;

void createTrie(char *str)
{
    int len=strlen(str);
    Trie *p=&root, *q;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(p->next[id]==NULL)
        {
            q=(Trie *)malloc(sizeof(root));
            q->v=1;
            for(int j=0;j<maxn;j++)
            {
                q->next[j]=NULL;
            }
            p->next[id]=q;
            p=p->next[id];
        }else{
            p->next[id]->v++;
            p=p->next[id];
        }
    }
}
int findTrie(char *str)
{
    int len=strlen(str);
    Trie *p=&root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        p=p->next[id];
        if(p==NULL)
        {
            return 0;
        }
    }
    return p->v;
}

int main()
{

    char str[15];
    int i;
    for(i=0;i<maxn;i++)
    {
        root.next[i]=NULL;
    }
    while(gets(str) && str[0]!='\0')
    {
        createTrie(str);
    }
    memset(str,0,sizeof(str));
    while(scanf("%s",str)!=EOF)
    {
        int ans=findTrie(str);
        printf("%d\n",ans);
    }
    return 0;
}
