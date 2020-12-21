//���Բ�·��ѹ�� ͨ��tarjan��
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
int f[manx], d[manx][manx];  //d��������ά��u��v�ľ��룬��ö�ٱߵ�ʱ����õ�
vector<int>p[manx]; //��չ·����path���飬��дp
struct node {
    int u, v, w;
    bool vis;  //�ȳ�����С����������vis�����жϱ��Ƿ������С�������ļ���
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
 
        for (int i = 1; i <= n; i++) {   //��ʼ������������֮�����Լ�
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
            a[i].vis = 1; //��ǽ�ȥ��С�������ļ���
            total++;
            int l1 = p[u].size(), l2 = p[v].size();
            for (int j = 0; j < l1; j++)
                for (int k = 0; k < l2; k++)
                    d[p[u][j]][p[v][k]] = d[p[v][k]][p[u][j]] = a[i].w; //��¼��С����������չ·���ľ���
            for (int j = 0; j < l1; j++) p[v].push_back(p[u][j]); //�ϲ�·�� 
            if (total == n) break;
        }
 
        ll res = inf; //��С�������ļ���
 
        for (int i = 1; i <= k; i++)
            if (!a[i].vis)  //ö��ÿ��û������С�������ļ���
                res = min(res, ans + a[i].w - d[a[i].u][a[i].v]);
 
        //ans����С��������Ȩֵ����ȥ��С��������u��v�����ߵ�Ȩֵ������ö�ٵ���һ���߽��бȽ�
        if (res > ans) cout << ans << endl;
        else cout << "Not Unique!" << endl;
    }
    return 0;
}
