#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=1e5+3,inf=2147483647;
int x,y,z,o=2,n,m,h,t,st,ed,Q[N],cur[N],dis[N],head[N];long long maxflow;
struct QAQ{
int to,next,flow;
}a[M<<1];
void add(int x,int y,int z){a[o].flow=z,a[o].to=y,a[o].next=head[x],head[x]=o++;}
int bfs(int st,int ed){
    for(int i=0;i<=n;++i)cur[i]=head[i],dis[i]=0; //每次都要cur因为 有可能虽然这次bfs用了这个路 但是 因为他的前导小，导致还有其他前导可以再用这个管子
    h=1,t=0,dis[st]=1,Q[++t]=st;
    while(h<=t){
        int x=Q[h++],to;
        for(int i=head[x];i;i=a[i].next)
            if(a[i].flow&&!dis[to=a[i].to]){
            	dis[to]=dis[x]+1,Q[++t]=to;
				if(to==ed){
				return 1;}
            }
    }
    return 0;
}
int dfs(int x,int flow){
    if(!flow||x==ed)return flow;
    int tmp=0,to,f;
    for(int i=cur[x];i;i=a[i].next){
    	cur[x]=i;
    	if(dis[to=a[i].to]==dis[x]+1&&(f=dfs(to,min(flow-tmp,a[i].flow)))){
            a[i].flow-=f;a[i^1].flow+=f;
            tmp+=f;
            if(!(flow-tmp))break;
    	}
    }
    return tmp;
}
void Dinic(int st,int ed){
    int flow=0;
    while(bfs(st,ed))maxflow+=dfs(st,inf);
}
int main(){
    cin>>n>>m>>st>>ed;
    while(m--)cin>>x>>y>>z,add(x,y,z),add(y,x,0);
    Dinic(st,ed);
    cout<<maxflow;
    return 0;
}
