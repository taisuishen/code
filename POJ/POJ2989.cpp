#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define For(i,j,k) for(int i = j;i <= (int)k;i ++)
#define Set(i,j) memset(i, j, sizeof(i))
 
using namespace std;
const int N = 130;
int Ans, G[N][N], all[N][N], some[N][N], none[N][N];
 
void DFS(int n, int an, int sn, int nn){
	if(!sn && !nn) Ans++;
	if(Ans > 1000) return;
	int key = some[n][1];
	For(j,1,sn){
		int v = some[n][j], tsn = 0, tnn = 0;
	//	cout<<key<<" "<<v<<endl; 
		if(G[key][v])continue;
		For(i,1,an) all[n+1][i] = all[n][i]; all[n+1][an+1] = v;
		For(i,1,sn) if(G[v][some[n][i]]) some[n+1][++tsn] = some[n][i];
		For(i,1,nn) if(G[v][none[n][i]]) none[n+1][++tnn] = none[n][i];
		DFS(n + 1, an + 1, tsn, tnn);
		some[n][j] = 0, none[n][++nn] = v;
	}
}
 
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		int x, y;
		Set(G, 0), Ans = 0;
		For(i,1,m){
			scanf("%d%d", &x, &y);
			G[x][y] = G[y][x] = 1;
		}
		For(i,1,n) some[1][i] = i;
		DFS(1, 0, n, 0);
		if(Ans > 1000) puts("Too many maximal sets of friends.");
		else printf("%d\n", Ans);
	}
	return 0;
}
 	BronKerbosch(All, Some, None):
       if Some and None are both empty:
           report All as a maximal clique //所有点已选完，且没有不能选的点,累加答案
       for each vertex v in Some: //枚举Some中的每一个元素
           BronKerbosch1(All ? {v}, Some ? N(v), None ? N(v)) 
           //将v加入All，显然只有与v为朋友的人才能作为备选，None中也只有与v为朋友的才会对接下来造成影响
           Some := Some - {v} //已经搜过，在Some中删除，加入None
           None := None ? {v}
