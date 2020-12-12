#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int n,xx0,xx1,yy0,yy1,ans;
struct node{
    int x,y,r;
}a[maxn];
int dis(int x,int y,node a){
    if((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)<=(a.r)*(a.r)) return 1;
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].r;
    for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		xx0=a[i].x;yy0=a[i].y;
		xx1=a[j].x;yy1=a[j].y;	
		ans=0;
		for(int k=1;k<=n;k++)
    	{
        if(dis(xx0,yy0,a[k])^dis(xx1,yy1,a[k])) ans++;
   		}
    	printf("%d -> %d = %d\n",i,j,ans);
	}
	return 0;

}
