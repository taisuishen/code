#include<bits/stdc++.h>
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define ll long long
using namespace std;
const int maxn=1000;
ll n,su[maxn],tot,anc,sum,a[maxn],sign,nn;
bool si[maxn]={0},use[maxn]={0},ua[maxn]={0};

 void get_list(){
       for(int i=2;i<=maxn;i++){
             if(!si[i]) su[++tot]=i;
             for(int j=1;j<=tot&&i*su[j]<=maxn;j++){
                   si[i*su[j]]=1;
                   if(i%su[j]==0) break;
             }
       }
}
void done()
{
	tot=1,anc=0,sum=1,sign=0;
	while(n-1)
	{
	while(n%su[tot]==0)anc++,n/=su[tot],a[sign++]=su[tot];
	sum*=(anc+1);
	anc=0;tot++;
	}
}

void dfs(int t)
{
	if(t>nn)return ;
	if(!use[t]&&sum--)cout<<t<<" ",use[t]=1;
	for(int i=0;i<sign;i++)
	if(!ua[i])
	{
	ua[i]=1;
	dfs(t*a[i]);
	ua[i]=0;
	}
}
int main()
{
	cin>>n;nn=n;
	get_list();
	done();
	dfs(1);                                                   
	return 0;
} 
