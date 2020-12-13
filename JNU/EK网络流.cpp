#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=1e5+3,inf=2e9;
int x,y,z,o=1,n,m,h,t,st,ed,maxflow,Q[N],cyf[N],vis[N],pre[N],head[N];
struct QAQ{int to,next,flow;}a[M<<1];

void add(int x,int y,int z){a[++o].flow=z,a[o].to=y,a[o].next=head[x],head[x]=o;}
int bfs(int st,int ed){
    for(int i=0;i<=n;++i)vis[i]=0;
    h=1,t=0,pan[st]=1,Q[++t]=st,cyf[st]=inf;//注意起点cfy的初始化
    while(h<=t){
        int x=Q[h++];
        for(int i=head[x],to;i;i=a[i].next)
            if(a[i].flow&&!vis[to=a[i].to]){//增广路上的每条边残留容量均为正
            	cyf[to]=min(cyf[x],a[i].flow);
            	//用cyf[x]表示找到的路径上从S到x途径边残留容量最小值
            	Q[++t]=to,pre[to]=i,vis[to]=1;//记录选择的边在链表中的下标
            	if(to==ed)return 1;//如果达到终点，说明最短增广路已找到，结束bfs
            }
    }
    return 0;
}
void EK(int st,int ed){
    while(bfs(st,ed)==1){
        int x=ed;maxflow+=cyf[ed];//cyf[ed]即为当前路径上边残留容量最小值
        while(x!=st){//从终点开始一直更新到起点
            int i=pre[x];
            a[i].flow-=cyf[ed];
            a[i^1].flow+=cyf[ed];
            x=a[i^1].to;//链表特性，反向边指向的地方就是当前位置的父亲
        }
    }
}
int main(){
    cin>>n>>m>>st>>ed;
    while(m--)cin>>x>>y>>z,add(x,y,z),add(y,x,0);
    EK(st,ed);
    printf("%d",maxflow);
}
