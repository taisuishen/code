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
        }//减去n-1里面判断是否可以通过函数 
        
       	for(int i = 1 ; i < n ; ++i)  
    	{
		    for(int p = 1 ; p <= n ; ++p) a[p] = p ;
		   	 for(int j = i ; j < n ; ++j)
	      	 	{
	            swap(a[j], a[j + 1]);
	            dfs(k,1);
	        	}
		}//从左至右加 
		
        for(int i = n-1 ; i >= 1 ; --i) 
       	{
			for(int p = 1 ; p <= n ; ++p) a[p] = p ;
				 for(int j = i ; j >= 1 ; --j) 
		      	{
		            swap(a[j+1], a[j]);
		            dfs(k,1);
		        }
    
  	  }//从右至左加 
        cout << ans << '\n';
    }

    return 0;
}
