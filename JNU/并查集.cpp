#include<cstdio>
#define maxn 10000+20
int fa[maxn];
int find(int x)
{
   return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        fa[find(a)]=find(b);
    }
    return 0;
}
