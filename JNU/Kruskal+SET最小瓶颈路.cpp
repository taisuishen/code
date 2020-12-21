#include <bits/stdc++>
using namespace std;
int n,m,q;
set<int>::iterator it;
const int maxm = 50005;
const int maxn = 11111;
set<int> Q[11111];
struct edge{
    int u,v,cost;
    friend bool operator <(edge e1,edge e2){
        return e1.cost > e2.cost;
    }
}es[maxm];
int ans[maxm];
int parent[maxn];
int find(int x){
    return x == parent[x]?x:parent[x] = find(parent[x]);
}
int main(){
    memset(ans,-1,sizeof(ans));
    for(int i = 1;i < maxn;++i)
        parent[i] = i;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;++i)
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    sort(es,es+m);
    scanf("%d",&q);
    for(int i = 0;i < q;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        Q[x].insert(i);
        Q[y].insert(i);
    }
    for(int i = 0;i < m;++i){
        int x = es[i].u,y = es[i].v,c = es[i].cost;
        int px = find(x),py = find(y);
        if(px == py) continue;
        else{
            if(Q[px].size() > Q[py].size())
                swap(px,py);
            vector<int> tmp;
            for(it = Q[px].begin();it != Q[px].end();++it){
                int id = *it;
                if(Q[py].count(id)){
                    ans[id] = c;
                    tmp.push_back(id);
                }
                Q[py].insert(id);
            }
            for(int i = 0;i < tmp.size();++i)
                Q[py].erase(tmp[i]);
            parent[px] = py;
        }
    }
    for(int i = 0;i < q;++i)
        printf("%d\n",ans[i]);
}