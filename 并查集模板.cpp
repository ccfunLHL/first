/*
ĳ������n���ˣ����ڸ�������n���˵�m����Ϣ��m����Ϣ����������ͬһ��С��������������Ϣ���ж���������������ж��ٸ�С����n���˱��Ϊ1~n��
����
�������롣
ÿ���һ������������n��m��2 <= n <= 50000�� 0 <= m <= n/2����
������m�У�ÿ����������a��b����ʾa��b��ͬһ��С����
���
����������Ϣ�������������������ж��ٸ�С����
ʾ������
5 2
1 2
3 4
ʾ�����
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
