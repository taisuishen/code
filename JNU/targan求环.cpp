#include<iostream>  //输出所有强连通分量
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,x,y,top=0,cnt=0,t,col;
int ans1=-1,ans2=-1,ans3=-1;
int d[200020];
int a[200020];
int c[200020];
int head[200020];
int dfn[200020];
int low[200020];
int stack[200020];

bool v[200020];

struct edge{
    int u,v,w,next;
}e[1000020];

void Add(int u,int v,int w)
{ 
    e[top].v=v;   e[top].next=head[u];    head[u]=top;
}

void tarjan(int now)
{
    dfn[now]=low[now]=++cnt;  //dfn  dfs遍历到这个点的顺序  low 在一条线不同递增  如果找到一个点曾经出现过  则更新然后回溯 
    stack[++t]=now;
    v[now]=1;
    for(int i=head[now];i;i=e[i].next)
        if(!dfn[e[i].v]) 
        {
            tarjan(e[i].v);
            low[now]=min(low[now],low[e[i].v]);
        }
        else if(v[e[i].v])
            low[now]=min(low[now],dfn[e[i].v]);    
    int cur;
    if(dfn[now]==low[now])
    {
        do
        {
            cur=stack[t--];
            v[cur]=false;
            printf("%d ",cur);
        }while(now!=cur);
        printf("\n");
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        add(x,y,0);
    }
    for(int i=1;i<=n;++i)
        if(!dfn[i]) tarjan(i);
    return 0;
}
