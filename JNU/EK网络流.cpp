#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=1e5+3,inf=2e9;
int x,y,z,o=1,n,m,h,t,st,ed,maxflow,Q[N],cyf[N],vis[N],pre[N],head[N];
struct QAQ{int to,next,flow;}a[M<<1];

void add(int x,int y,int z){a[++o].flow=z,a[o].to=y,a[o].next=head[x],head[x]=o;}
int bfs(int st,int ed){
    for(int i=0;i<=n;++i)vis[i]=0;
    h=1,t=0,pan[st]=1,Q[++t]=st,cyf[st]=inf;//ע�����cfy�ĳ�ʼ��
    while(h<=t){
        int x=Q[h++];
        for(int i=head[x],to;i;i=a[i].next)
            if(a[i].flow&&!vis[to=a[i].to]){//����·�ϵ�ÿ���߲���������Ϊ��
            	cyf[to]=min(cyf[x],a[i].flow);
            	//��cyf[x]��ʾ�ҵ���·���ϴ�S��x;���߲���������Сֵ
            	Q[++t]=to,pre[to]=i,vis[to]=1;//��¼ѡ��ı��������е��±�
            	if(to==ed)return 1;//����ﵽ�յ㣬˵���������·���ҵ�������bfs
            }
    }
    return 0;
}
void EK(int st,int ed){
    while(bfs(st,ed)==1){
        int x=ed;maxflow+=cyf[ed];//cyf[ed]��Ϊ��ǰ·���ϱ߲���������Сֵ
        while(x!=st){//���յ㿪ʼһֱ���µ����
            int i=pre[x];
            a[i].flow-=cyf[ed];
            a[i^1].flow+=cyf[ed];
            x=a[i^1].to;//�������ԣ������ָ��ĵط����ǵ�ǰλ�õĸ���
        }
    }
}
int main(){
    cin>>n>>m>>st>>ed;
    while(m--)cin>>x>>y>>z,add(x,y,z),add(y,x,0);
    EK(st,ed);
    printf("%d",maxflow);
}
