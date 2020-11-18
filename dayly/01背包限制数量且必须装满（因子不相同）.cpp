#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=(int)1e3;
int n,f[N][N]={1};
int main(void)
{
	
	cin>>n;
	FOR(i,1,n)
		ROF(j,n,i)
			FOR(k,1,3)
				f[j][k]=max(f[j][k],f[j-i][k-1]*i);
	cout<<f[n][3]<<endl;
}
