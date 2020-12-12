#include<bits/stdc++.h>
#define maxn 10000+20
using namespace std;
int fa[maxn];
int find(int x)
{
   return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node
{
	int x,y,w;
}p[maxn];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
    int n,m,a,b,w,tot=0,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
    }
    sort(p+1,p+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
    	if(find(p[i].x)!=find(p[i].y))ans+=p[i].w,++tot,fa[find(p[i].x)]=find(p[i].y);
    	if(tot==n-1)break;
	}
	printf("%d\n",ans);
    return 0;
}
