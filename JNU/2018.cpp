/*code_by_taisuishen*/ 
#include<bits/stdc++.h>
using namespace std;
//1模拟 
int n,a[100],m;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-m;i++)swap(a[i],a[(i+m)%n]);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	return 0;
}

//2模拟，可以栈来做但是没必要，题目只要一个合法序列即可 
int n;
int main()
{
	cin>>n;
	if(n%2)
	{
		for(int i=1;i<=n;i+=2)cout<<i<<" ";
		for(int i=2;i<=n-1;i+=2)cout<<i<<" ";
	}
	else
	{
		for(int i=1;i<=n-1;i+=2)cout<<i<<" ";
		for(int i=2;i<=n;i+=2)cout<<i<<" ";
	}
	return 0;
}
 
//3.dfs or 模拟（速度更快） 
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int anc[maxn],n,x,l,r,maxx=0;
struct node
{
	int left,right;
	node()
	{
		left=0;right=0;
	}
}a[maxn];
void dfs(int le,int t)
{
	anc[le]+=(a[t].left?1:0)+(a[t].right?1:0);
	maxx=max(maxx,anc[le]);
	if(a[t].left)dfs(le+1,a[t].left);
	if(a[t].right)dfs(le+1,a[t].right);
}
int main(){
	cin>>n;//输入n个节点及左右儿子 0为空 第一个x为根节点1 
	while(n--)
	{
		cin>>x>>l>>r;
		a[x].left=l,a[x].right=r;
	}
	dfs(1,1); 
	cout<<maxx<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int anc[maxn],n,x,maxx=0;
int t[maxn]={1,2,4,8,16,32,64,128,256,512,1024,2048,5096};//打表得 根据题意扩充 
int check(int p)
{
	for(int i=0;i<=maxn;i++)
		if(p<t[i])return i-1;
}
int main(){
	int l,r;
	cin>>n;//输入n个节点及左右儿子 0为空 第一个x为根节点1 
	while(n--)
	{
		cin>>x>>l>>r;
		if(l)anc[check(l)]++,maxx=max(anc[check(l)],maxx);
		if(r)anc[check(r)]++,maxx=max(anc[check(r)],maxx);
	} 
	cout<<maxx<<endl;
	return 0;
}

/*
7
1 2 0
2 4 5
4 8 0
5 10 11
8 0 0
10 0 0
11 0 0
*/
 
//4..送分题 
string s;
int n,ans=0;
int main(){
	cin>>n;
	while(n--)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)ans++;
	}
	cout<<ans<<endl;	
} 


//5.群题目描述不清，但多半是类似求最短路 直接dijkstra+heap 起点默认为s=1 终点=n 
#include <bits/stdc++.h>
using namespace std;
int n,m,s=1;
int head[100001],dis[100001],cnt;
bool vis[100001];
struct qwq{
int from,to,next;
long long len;
}edge[200001];
void add(int u,int v,int w)
{
     cnt++;
     edge[cnt].from=u;
     edge[cnt].to=v;
     edge[cnt].len=w;
     edge[cnt].next=head[u];
     head[u]=cnt;
     return;
}
struct node{
     int index,dist;
     bool operator < (const node &x)const
     {
         return dist>x.dist;
     }
};
priority_queue<node> q; 
int main()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)
     {
         int u,v,w;
         scanf("%d%d%d",&u,&v,&1);
         add(u,v,w);
     }
     for(int i=1;i<=n;i++)
     dis[i]=2147483647;
     dis[s]=0;
     q.push(node{s,0});
     while(!q.empty())
     {
         node x=q.top();
         q.pop();
         int u=x.index;
         if(vis[u]) continue;
         vis[u]=1;
         for(int i=head[u];i;i=edge[i].next)
         {
             if(dis[edge[i].to]>dis[u]+edge[i].len)
             {
                 dis[edge[i].to]=dis[u]+edge[i].len;
                 q.push(node{edge[i].to,dis[edge[i].to]});
             }
         }
     }
     printf("%d ",dis[n]);
     return 0;
}


//6动规问题  可单调队列优化至O（VN） 
int a[7],x,f[5000],w[7]={0,1,5,10,25,100,500},tot=0;
int main()
{
	memset(f,0x3f3f3f3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=6;i++)cin>>a[i],tot+=a[i];
	cin>>x;
	for(int i=1;i<=6;i++)
	{
		int num=min(a[i],x/w[i]);
		for(int j=1;num>0;j<<=1)
		{
			j=j>num?num:j;
			num-=j;
			for(int k=x;k>=w[i]*j;k--)f[k]=min(f[k],f[k-w[i]*j]+j);
		}
	}
	if(f[x]>tot)cout<<"NOWAY"<<endl;
	else
	cout<<f[x]<<endl;
	return 0;
}



//7.01背包 
int w[5],c[5],f[2000]={0};
int main()
{
	for(int i=1;i<=4;i++)cin>>w[i]>>c[i];
	for(int i=1;i<=4;i++)
	{
		for(int j=9;j>=w[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
	}
	cout<<f[9]<<endl;
return 0;
}


//8.二分 分治解决 
int maxx=0,minn=10000000;
int n,a[2000];
void find(int l,int r)
{
	if(l==r)
	{
		minn=minn>a[l]?a[l]:minn;
		maxx=maxx>a[l]?maxx:a[l];
		return ;
	}
	else
	{
		find(l,(r+l)/2);
		find((r+l)/2+1,r);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	find(0,n-1);
	cout<<maxx<<endl<<minn<<endl;
	return 0;
} 

