#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 55;
int a[N], b[N] ;
int n, k, T, mod;
int from[N], to[N] ;
int ans;
void dfs(int i, int f) {
    if(i == 0) {
        ans += f;
        if(ans >= mod) ans -= mod;
        return ;
    }
    if(a[from[i]] < a[to[i]]) {
        dfs(i - 1, f) ;
        swap(a[from[i]], a[to[i]]) ;
        dfs(i - 1, f) ;
        swap(a[from[i]], a[to[i]]) ;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> k >> mod;
        for(int i = 1 ; i <= k ; ++i) cin >> from[i] >> to[i] ;
        for(int i = 1 ; i <= n ; ++i) a[i] = i ;
        ans = 0;
        dfs(k, 1) ;
        for(int i = 1 ; i < n ; ++i) {
            swap(a[i], a[i + 1]);
            dfs(k, -1);
            swap(a[i], a[i + 1]);
        }
        for(int take = 1 ; take <= n ; ++take) {
            for(int i = 1 ; i <= n ; ++i) {
                if(i == take) continue ;
                int cur = 0;
                for(int j = 1 ; j <= n ; ++j) {
                    if(cur == take - 1) cur++;
                    if(i == j) a[j] = take ;
                    else a[j] = ++cur;
                }
                dfs(k , 1);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
