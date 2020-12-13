#include<bits/stdc++.h>
using namespace std;
#define INF (1<<31)-1
struct Edge{
    int to,next,value;
}edge[1000005];
bool vis[20005];
int tot,head[20005],d[20005],start;
void add(int u,int v,int w){
    tot++,edge[tot].to=v,edge[tot].value=w,edge[tot].next=head[u],head[u]=tot;
}
void dijskra(){
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
 int n,m,fuck,u,v,w,now,minn=INF,Q;
    cin>>n>>m>>start;
    for(register int i=1;i<=n;i++)
    	d[i]=INF;
    for(register int i=0;i<m;i++)
        cin>>u>>v>>w,add(u,v,w);
    d[start]=0,now=start;
    dijskra();
    for(register int i=1;i<=n;i++)
    cout<<d[i]<<endl;
return 0;
} 