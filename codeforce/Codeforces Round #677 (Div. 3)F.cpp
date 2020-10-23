#include<bits/stdc++.h>
using namespace std;
int n,m,kk,a[80][80],las=0,f[80][80][80][80];

int main()
{
	memset(f,-1,sizeof(f));
	f[1][0][0][0]=0;
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=min(j,m/2);k++)
			{
				for(int p=0;p<kk;p++)
				{	
					f[i][j][k][p]=max(f[i][j][k][p],f[i][j-1][k][p]);
					if(k&&f[i][j-1][k-1][p]!=-1)
					f[i][j][k][(p+a[i][j])%kk]=max(f[i][j][k][(p+a[i][j])%kk],f[i][j-1][k-1][p]+a[i][j]);
				}
				for(int p=0;p<kk;p++)f[i+1][0][0][p]=max(f[i+1][0][0][p],f[i][j][k][p]);
			}
	cout<<max(f[n+1][0][0][0],0);
	return 0;
}
