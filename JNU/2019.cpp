/*code_by_taisuishen*/
#include<bits/stdc++.h>
using namespace std;
#define change(a,b) a^=b^=a^=b
const int maxn=1e3;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') y=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*y;
}
 //1题 模拟 
bool A(char c){
	return c<='Z'&&c>='A'?1:0;
}
string s;
int tot=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)if(A(s[i]))tot++;
	for(int i=0;i<s.size();i++)
	{
		if(tot+tot>=s.size()&&!A(s[i]))s[i]-=32;
		else if(tot+tot<s.size()&&A(s[i]))s[i]+=32;
	}
	cout<<s<<endl;
	return 0;
}

 //2题 模拟 
int n,m,p,q,step,a[maxn];
int find(int k){
	for(int i=1;i<=n;i++)if(a[i]==k)return i;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=i;
	while(m--){
		step=0;
		p=read();q=read();
		p=find(p);
		if(q>0)
			while(++step<=q)change(a[p+step-1],a[p+step]);
		else while(--step>=q)change(a[p+step+1],a[p+step]);

	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}

//3题 模拟 
bool cmp(string a,string b){
	if(a.size()<b.size()){
		for(int i=0;i<a.size();i++)if(a[i]>b[i])return 0;
		return 1;
	}
	else if(b.size()<a.size()){
		for(int i=0;i<b.size();i++)if(b[i]>a[i])return 1;
		return 0;
	}
	else {
		for(int i=0;i<a.size();i++)if(a[i]>b[i])return 0;
		return 1;
	}
}
string s[maxn],x,t="";
int tot=0;
int main(){
	getline(cin,x); 
	for(int i=0;i<x.size();i++){
		if(x[i]!=' ')	t+=x[i]<='Z'?x[i]+32:x[i];
		if(x[i]==' '||i==x.size()-1)s[tot++]=t,t="";
		 
	}
	sort(s,s+tot,cmp);
	for(int i=0;i<tot;i++)cout<<s[i]<<endl;
	return 0;
}
 //第四题 最小生成树 
int fa[maxn];
struct node{
	int x,y;
	int fi,to;
	double w;
}a[maxn],b[maxn];
bool cmp(node p,node q){
	return p.w<q.w;
}
int find(int x){return x==fa[x]?x:find(fa[x]);
}
double dis(node p,node q){
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
} 
int n,m,u,v,fv,fu,sign[maxn][maxn]={0};
int main(){
	n=read();m=read();
	
	for(int i=0;i<n;i++)
	{
		fa[i+1]=i+1;
		a[i].x=read();a[i].y=read();
	}
	int las=0;
	for(int i=0;i<m;i++)
	{
		u=read();v=read();
		sign[u][v]=sign[v][u]=1;
		fu=find(u);fv=find(v);
		if(fu!=fv)fa[fu]=fv,las++;
	}
	int tot=0;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=i;j++)
	 	if(i-j&&!sign[i][j]){
	 		b[tot].fi=i;b[tot].to=j;
	 		b[tot].w=dis(a[i-1],a[j-1]);
	 		tot++;
	 	}
	sort(b,b+tot,cmp);
	double sum=0;
	
	for(int i=0;i<tot;i++)
	{
	 	fu=b[i].fi;fv=b[i].to;
	 	cout<<b[i].fi<<" "<<b[i].to<<endl;
	 	if(fu!=fv)fa[fu]=fv,sum+=b[i].w,las++;
	 	if(las==n-1)break;
	}
	cout<<sum<<endl;
	return 0;
}

//第五题 字符串处理 
string ex[300];
stack<int >k;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num=0;
        char s[305];
        cin>>s;
	int len=strlen(s);
	getchar();
        for(int i=0;i<len;i++)
        {
            string st;
            st=st.substr(0,0);//每次运行都要将临时字符串初始化
            if(isalpha(s[i]))
            {
                st=st+s[i]+s[i+1]+s[i+2];
                i=i+2;
                ex[num++]=st;
            }
            else if(s[i]=='(')
            {
               continue;
            }
            else if(isdigit(s[i]))
            {
                int j;
                for( j=i;s[j]!=','&&s[j]!=')';j++)st+=s[j];
                k.push(atoi(st.c_str()));
                i=j-1;
            }
			else if(s[i]==',')
				continue;
            else           
            {
                int a,b;
                string c;
                a=k.top();k.pop();
                b=k.top();k.pop();
                c=ex[num-1];
                if(c=="min")
                    a=min(a,b);
                else if(c=="max")
                    a=max(a,b);
                else if(c=="add")
                    a=a+b;
                k.push(a);
                num--;
            }
        }
        int ans=k.top();
        cout<<ans<<endl;
    }

}
//第六题  搜索 可以+记忆化或者DP 
int ma[maxn][maxn];
int n,m,minn=maxn;
int dx[2]={1,0};
int dy[2]={0,1};
bool check(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	return 0;
}
void dfs(int x,int y,int sum){
	if(x==n&&y==m)minn=minn<sum?minn:sum;
	//cout<<sum<<endl;
	for(int i=0;i<2;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(check(xx,yy))
		dfs(xx,yy,sum+ma[xx][yy]);
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ma[i][j]=read();
		}
	dfs(1,1,ma[1][1]);
	cout<<minn;
	return 0;
} */
/*eg
4 4
1 2 3 4
4 8 3 2
6 1 4 5
7 3 7 8
*/ 
 //第七题  灌水 
int n,m,nx,ny,vis[maxn][maxn]={0},ans=0;
char ma[maxn][maxn];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<m&&ma[x][y]!='#')return 1;
	return 0;
}
void dfs(int x,int y){
	vis[x][y]=1;
	ans++;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(check(xx,yy)&&!vis[xx][yy])dfs(xx,yy);
	}
}
int main(){
	m=read();n=read();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		
			{
			scanf("%c",&ma[i][j]);
			if(ma[i][j]=='@')nx=i,ny=j;
			}
			getchar();
		}
	dfs(nx,ny);
	cout<<ans<<endl;
	return 0;
} 
//第八题 DP is 分治，最优子结构 
int n,m,fa[maxn],f[maxn];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)fa[i]=read();
	for(int i=1;i<=m;i++)f[i]=maxn;
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
		{
			if(j-fa[i]>=0)
			f[j]=min(f[j],f[j-fa[i]]+1);
		}
	cout<<f[m];
	return 0;
		
} 
