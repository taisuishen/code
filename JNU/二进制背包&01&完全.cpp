int a[7],x,f[5000],w[7]={0,1,5,10,25,100,500},tot=0;
int main()
{
	memset(f,0x3f3f3f3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=6;i++)cin>>a[i],tot+=a[i];
	cin>>x;
	for(int i=1;i<=6;i++)
	{
		int num=min(a[i],x/w[i]);
		for(int j=1;num>0;j<<=1)
		{
			j=j>num?num:j;
			num-=j;
			for(int k=x;k>=w[i]*j;k--)f[k]=min(f[k],f[k-w[i]*j]+j);
		}
	}
	if(f[x]>tot)cout<<"NOWAY"<<endl;
	else
	cout<<f[x]<<endl;
	return 0;
}