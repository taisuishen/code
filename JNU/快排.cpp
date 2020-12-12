#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000+10];
void qsort(int l,int r){
	int si=a[(l+r)/2],i=l,j=r;
	while(i<=j){
		while(a[i]<si)i++;
		while(a[j]>si)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}

	}
	if(l<j)	qsort(l,j);
	if(i<r)	qsort(i,r);

}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";

	return 0;

} 
