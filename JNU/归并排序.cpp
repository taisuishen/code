#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
int a[maxn],b[maxn],n;
void Merge(int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)/2;
    Merge(l,mid);
    Merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])b[k++]=a[j++];
        else b[k++]=a[i++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	Merge(0,n-1);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	return 0;
	
}
