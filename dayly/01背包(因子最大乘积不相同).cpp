#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=(int)1e5;
int n,f[N];
int main(void)
{
	FOR(i,0,n)f[i]=1;
	cin>>n;
	FOR(i,1,n)
		ROF(j,n,i)
			f[j]=max(f[j],f[j-i]*i);
	cout<<f[n]<<endl;
}
