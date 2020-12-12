#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
 //1.链表
int n,x,y;
struct node
{
	int num;
	node *next;
};
int main()
{
	node *p,*head,*q;
	cin>>n;
	cin>>x;
	p=new node;
	p->num=x;p->next=NULL;
	head=p;
	while(--n)
	{
		cin>>x;
		q=new node;
		q->num=x;q->next=NULL;
		p->next=q;
		p=p->next;
	}
	cin>>x;
	if(head->num==x){
		p=head->next;
		free(head);
		head=p;
	}
	else
	{
		p = head, q = head->next;
	    while(q != NULL && q->num != x){  
			p = q;
			q = q->next;
	}
		if(q != NULL && q->num == x){     
			p->next = q->next;                
			free(q);
	}

	}
	p=head;
	while(p!=NULL)
	{
		cout<<p->num<<endl;
		p=p->next;
	}
	return 0;
}

 2.paixushu

int a[maxn]={0,10,18,9,2,20,5,6,15,19,25},b[maxn],si[maxn];
void done(int now,int p)
{
	if(!si[now])
	{
		si[now]=1;
		b[now]=a[p];
		cout<<now<<" "<<a[p]<<endl;
		return ;
	}
	if(a[p]<b[now])done(now*2,p);
	else done(now*2+1,p);
}
int main(){
	b[1]=a[1];
	si[1]=1;
	for(int i=2;i<10;i++)done(1,i);
	return 0;
}
/*print
3 18
2 9
4 2
7 20
9 5
19 6
6 15
14 19*/
3.sort print:24 31 38 40 46 56 79 80 95
int a[maxn]={46,79,56,38,40,80,31,95,24};
void qsort(int l,int r)
{
	int i=l,j=r;
	int si=a[l];
	if(l>=r)return ;
	while(i<j)
	{
		while(a[j]>=si&&i<j)j--;
		a[i]=a[j];
		while(a[i]<=si&&i<j)i++;
		a[j]=a[i];
	}
	a[i]=si;
	qsort(l,i-1);
	qsort(i+1,r);
}
int main()
{
	qsort(0,8);
	for(int i=0;i<9;i++)cout<<a[i]<<" ";
	return 0;
}

//4.可以用栈没必要 直接模拟

int i=0;
string s;
int main()
{
	cin>>s;
	for(int k=0;k<s.size();k++)
	{
		if(s[k]=='I')i++;
		else i--;
		if(i<0)
		{
			printf("非法\n");
			return 0;
		}
	}
	printf("合法\n");
	return 0;
}

//5 二叉树
struct bitree
{
	bitree *left,*right;
};
void counterleaf(bitree *t,int &count) 
{
	if(t==NULL)return ;
	if(t->left==NULL&&t->right==NULL)
	{
	count++;
	}
	counterleaf(t->left,count);
	counterleaf(t->right,count);
}

void build(bitree *t)
{
	int x,y;
	bitree *p,*q;
	cin>>x>>y;
	t->left=NULL;t->right=NULL;
	if(x)
	{
		p=new bitree;
		t->left=p;
		build(p);
	}
	if(y)
	{
		q=new bitree;
		t->right=q;
		build(q);
	}
}
int x,y;
int main()
{
	int n,count=0;
	bitree *root,*t;
	root=new bitree;
	t=root;
	build(t);
	counterleaf(root,count);
	cout<<count<<endl;
	return 0;
}



//6.贪心
int n,w,a[maxn],ans=0;
int main()
{
	cin>>w>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=n-1,j=0;i>=j;i--)
	{
		ans++;
		if(a[j]+a[i]<=w)j++;
	}
	cout<<ans<<endl;
	return 0;
	
}


//7.DP
#include <bits/stdc++.h>
using namespace std;
const int seed=131;
const int M = 1e3+7;
 
char a[M],b[M];
int dp[M][M];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>a>>b){
    	memset(dp,0,sizeof(0));
    	int l=strlen(a);
    	for(int i=1;i<=l;i++)
			for(int j=1;j<=l;j++){
    		dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    		if(b[i-1]==a[j-1]&&dp[i][j]<dp[i-1][j-1]+1)dp[i][j]=dp[i-1][j-1]+1;
		}
		cout<<dp[l][l]<<endl;
	}
   
  	return 0;
}


//8.区间DP
int n;
int a[11]={0,12,21,31,40,49,58,69,79,90,101};
int f[maxn];
int main()
{
	memset(f,0x3f3f3f3f,sizeof(f));
	cin>>n;
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=min(i,10);j++)
		f[i]=min(f[i],f[i-j]+a[j]);
		
	cout<<f[n];
	return 0;
}

