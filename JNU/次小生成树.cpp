//可以不路径压缩 通过tarjan求环
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
#define R register int
#define inf 0x3f3f3f3f
using namespace std;
const int manx = 200 + 5;
const int mamx = 1e5 + 5;
int n, m, u, v, w, k;
int f[manx], d[manx][manx];  //d数组用来维护u到v的距离，在枚举边的时候会用到
vector<int>p[manx]; //扩展路径，path数组，缩写p
struct node {
    int u, v, w;
    bool vis;  //比常规最小生成树多了vis属性判断边是否加入最小生成树的集合
}a[mamx];
bool cmp(node a, node b){
    return a.w < b.w;
}
 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
 
int main()
{
    int t; cin >> t;
    while (t--){
        k = 0;
        scanf("%d%d", &n, &m);
 
        for (int i = 1; i <= n; i++) {   //初始化操作，万物之父皆自己
            p[i].clear();
            p[i].push_back(i);
            f[i] = i;
        }
 
        for (int i = 1; i <= m; i++){
            scanf("%d%d%d", &u, &v, &w);
            a[++k].u = u, a[k].v = v, a[k].w = w, a[i].vis = false;
        }
 
        sort(a + 1, a + 1 + k, cmp);
        ll ans = 0;
        int total = 1;
 
        for (int i = 1; i <= k; i++){
            u = find(a[i].u), v = find(a[i].v);
            if (u == v) continue;
            ans += a[i].w;
            f[u] = v;
            a[i].vis = 1; //标记进去最小生成树的集合
            total++;
            int l1 = p[u].size(), l2 = p[v].size();
            for (int j = 0; j < l1; j++)
                for (int k = 0; k < l2; k++)
                    d[p[u][j]][p[v][k]] = d[p[v][k]][p[u][j]] = a[i].w; //记录最小生成树中扩展路径的距离
            for (int j = 0; j < l1; j++) p[v].push_back(p[u][j]); //合并路径 
            if (total == n) break;
        }
 
        ll res = inf; //次小生成树的集合
 
        for (int i = 1; i <= k; i++)
            if (!a[i].vis)  //枚举每条没加入最小生成树的集合
                res = min(res, ans + a[i].w - d[a[i].u][a[i].v]);
 
        //ans是最小生成树的权值，减去最小生成树中u到v这条边的权值，加上枚举的这一条边进行比较
        if (res > ans) cout << ans << endl;
        else cout << "Not Unique!" << endl;
    }
    return 0;
}
