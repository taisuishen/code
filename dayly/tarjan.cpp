#include<bits/stdc++.h> 
using namespace std;
vector<int> e[100050],ans,p;
stack<int> s;
int low[100050],dfn[100050],vis[100050],cnt;
void pr(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	ans.clear();
	while(!s.empty())s.pop();
}
void tarjan(int u,int pre){
	dfn[u] = low[u] = ++ cnt;
	s.push(u);
	vis[u] = 1;
	for(int i = 0;i < e[u].size();i ++)
	{
		int v = e[u][i];
		if(v == pre) continue;          
		if(dfn[v] == 0){
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
		}
		else if(vis[v] == 1){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		vector<int> path;
		while(1){
			int t = s.top();
			s.pop();
			path.push_back(t);
			vis[t] = 0;
			if(t == u) break; 
		}
		if(path.size() > 1){
			ans = path;
			return ;
		}
	}
}
int main()
{
	int n,a,b,m,num=1;
	cin>>n>>m;
	for(int i = 1;i <= m;i ++){
		cin>>a>>b;
		e[a].push_back(b);
	}
	for(int i = 1;i <= n;i ++){
		{
		p=ans;
		pr();
		tarjan(i,-1);
		sort(ans.begin(),ans.end());
		int sign=1;
		if(p.size()!=ans.size())sign=0;
		else
		for(int i = 0;i < ans.size();i ++)if(p[i]!=ans[i])sign=0;
		if(!sign)
		{
		cout<<"»·"<<num++<<":"; 
		for(int i = 0;i < ans.size();i ++){
		{
			
		cout<<ans[i];
		if(i == ans.size() - 1) cout<<endl;
		else cout<<" ";
		}
		}}
	}
	}

	return 0;
}
