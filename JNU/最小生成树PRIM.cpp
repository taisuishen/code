#include<bits/stdc++.h> 
using namespace std;
const int maxn=1000005;
const int MAXN=123465789;

struct node{
	int to,w,nxt;
}t[maxn];

int n,m,tot,head[maxn],dis[maxn],a,b,c; //¡¥ Ω«∞œÚ–« 
bool vis[maxn];

int ans,cnt,now=1;//Prim

void add(const int u,const int v,const int w)
{
	t[++tot].to=v;
	t[tot].w=w;
	t[tot].nxt=head[u];
	head[u]=tot;
}

void prim()
{
	for(int i=2;i<=n;++i)
		dis[i]=MAXN;
		
	for(int i=head[1];i;i=t[i].nxt)
		dis[t[i].to] = min(dis[t[i].to],t[i].w);
	
	while(++cnt<n)
	{
		int minn=MAXN;
		vis[now]=1;
		for(int i=1;i<=n;++i)
		{
			if(vis[i]) continue;
			if(minn > dis[i])
			{
				minn=dis[i];
				now=i;
			}
		} 
		
		ans+=minn;
		
		for(int i=head[now];i;i=t[i].nxt)
		{
			int y=t[i].to;
			if(vis[y]) continue;
			if(dis[y] > t[i].w)
			{
				dis[y]=t[i].w;
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	prim();
	printf("%d\n",ans);
}
