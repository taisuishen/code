#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100000;
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
int main()
{
	get_list();
	while(cin>>n)
	{
		int fi=0;
		cout<<n<<"=";
		for(int i=1;i<=tot;i++)
		{
		if(!fi&&n%su[i]==0)fi=1,n/=su[i],cout<<su[i];
		while(n%su[i]==0)n/=su[i],cout<<"*"<<su[i];
		}
		cout<<endl;
	}
	return 0;
} 
