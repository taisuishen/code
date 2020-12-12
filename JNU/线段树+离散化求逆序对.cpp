#include<bits/stdc++.h>
#define lson l,m,rt*2  
#define rson m+1,r,rt*2+1   
#define maxn 100000+10
using namespace std;  
int n,now[maxn],tree[4*maxn],sign=0,ans=0;  
const int mod=99999997;
struct node{  
    int v,w;  
}a[maxn],b[maxn];  
bool cmp(node a,node b)  
{  
    return a.v<b.v;  
}  
void pushup(int rt)  
{  
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];   
}  
void ins(int p, int l, int r, int rt)    
{    
    if( l == r )    
    {    
        tree[rt] ++;    
        return ;    
    }    
    int m = ( l + r ) >> 1;    
    if(p <= m)    
        ins(p,lson);    
    else    
        ins(p,rson);    
    
    pushup(rt);    
}    
int query(int L,int R,int l,int r,int rt)//要询问的区间L-R   
{  
    if(l>=L&&r<=R)  
    {  
        return tree[rt];  
    }  
    int m=(l+r)>>1;  
    int ans=0;  
    if(L<=m)ans+=query(L,R,lson);  
    if(R>m)ans+=query(L,R,rson);  
    return ans;  
}  
int main()  
{  
    cin>>n;  
    for(int i=1;i<=n;i++)  
    {  
        cin>>a[i].v; a[i].w=i;  
    }  
    for(int i=1;i<=n;i++)  
    {  
    	cin>>b[i].v; b[i].w=i;  
    }  
    sort(a+1,a+1+n,cmp);  
    sort(b+1,b+1+n,cmp);  
    
    for(int i=1;i<=n;i++) now[b[i].w]=a[i].w;  
    
    for(int i=1;i<=n;i++)  
    {  
        ins(now[i],1,n,1);
		ans=(ans+i-query(1,now[i],1,n,1))%mod;    
    }  
    cout<<ans;  
    return 0;  
}  
