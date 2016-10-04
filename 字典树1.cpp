#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=10;
typedef struct Trie{
    int v;
    Trie *next[maxn];
}Trie;
Trie *root;
void createTrie(char *str)
{
    int len=strlen(str);
    Trie *p=root, *q;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(p->next[id]==NULL)
        {
            q=(Trie *)malloc(sizeof(Trie));
            q->v=1;
            for(int j=0;j<maxn;j++)
            {
                q->next[j]=NULL;
            }
            p->next[id]=q;
            p=p->next[id];
        }else
        {
            p->next[id]->v++;
            p=p->next[id];
        }
    }
    p->v=-1;
}
int findTrie(char *str)
{
    int len=strlen(str);
    Trie *p=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        p=p->next[id];
        if(p==NULL) return 0;
        if(p->v==-1) return -1;
    }
    return -1;
}
int deal(Trie* T)
{
    if(T==NULL) return 0;
    for(int i=0;i<maxn;i++)
    {
        if(T->next[i]!=NULL)
            deal(T->next[i]);
    }
    free(T);
    return 0;
}



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[20];
        bool flag;
        flag=0;
        root=(Trie *)malloc(sizeof(Trie));
        for(int i=0;i<maxn;i++)
        {
            root->next[i]=NULL;
        }
            int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            if(findTrie(str)==-1)
                flag=1;
            if(flag) continue;
            createTrie(str);
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
        deal(root);
    }


}
