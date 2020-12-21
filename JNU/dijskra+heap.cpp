#include<bits/stdc++.h>
using namespace std;
#define INF (1<<31)-1
struct Edge{
    int to,next,value;
}edge[1000005];
bool vis[20005];
int tot=0,head[20005],d[20005],start,n,m;
void add(int u,int v,int w){
    tot++,edge[tot].to=v,edge[tot].value=w,edge[tot].next=head[u],head[u]=tot;
}
void dijskra(){
	for(int i=1;i<=n;i++)
    	d[i]=INF;
    d[start]=0;
    priority_queue<pair<int,int>,vector<pair<int, int> >, greater<pair<int,int> > > q;  	
    q.push(make_pair(0,start));
    while(!q.empty())
    {
        int x=q.top().second;  q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].to;
            int z=edge[i].value;
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(d[y],y));
            }
        }
    }
}

int main()
{
 	int u,v,w;
 	
    cin>>n>>m>>start;
    
    for(int i=0;i<m;i++)	cin>>u>>v>>w,add(u,v,w);

    dijskra();
    
    for(int i=1;i<=n;i++)	cout<<d[i]<<" ";
return 0;
} 
