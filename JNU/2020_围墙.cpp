#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int maxn=100000;
int n,ans,sum=0,A,B,C;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') y=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return (double)x*y;
}
struct node
{
	double x,y,r;
}a[maxn];
bool check(int z,int p)
{
	if((a[z].x-a[p].x)*(a[z].x-a[p].x)+(a[z].y-a[p].y)*(a[z].y-a[p].y)<=a[z].r*a[z].r)return 1;
	return 0;
}
int done(int p,int q,int z)
{
	if(check(z,p)&&check(z,q))return 0;
	else if((check(z,p)==0&&check(z,q)||(check(z,p)&&check(z,q)==0)))return 1;//其实一个点在圆内 穿一堵墙 
	if(a[p].x==a[q].x)A=1,B=0,C=-a[p].x;
	else if(a[p].y==a[q].y)A=0,B=1,C=-a[p].y;
	else
	{
		A=a[p].y-a[q].y;
		B=a[q].x-a[p].x;
		C=a[p].x*a[q].y-a[p].y*a[q].x;
	}
	if(A*a[z].x+B*a[z].y+C>(A*A+B*B)*a[z].r*a[z].r)return 0;
	if((a[z].x-a[p].x)*(a[q].x-a[p].x)+(a[z].y-a[p].y)*(a[q].y-a[p].y)>0&&(a[z].x-a[q].x)*(a[p].x-a[q].x)+(a[z].y-a[q].y)*(a[p].y-a[q].y)>0)return 2;  //穿过整个圆 
	return 0; 
}
int main()
{	
	n=read();
	FOR(i,1,n)a[i].x=read(),a[i].y=read(),a[i].r=read();
	FOR(i,1,n-1)
	{
		ans=0;
		FOR(j,i+1,n)
		if(i!=j)
		{
			ans=0;
			FOR(k,1,n)
				ans+=done(i,j,k);
			printf("%d->%d:%d\n",i,j,ans);
		}
	}
	return 0;
} 
