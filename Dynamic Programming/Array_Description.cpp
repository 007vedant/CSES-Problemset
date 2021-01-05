#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7;
const int N = 2e5+5;

int calc(int n, int m, vector<int>& arr)
{
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));
 
    rep(i, 1, n+1)
    {
        rep(x, 1, m+1)
        {
            if(i == 1)
            {
                if(arr[i] == 0 || arr[i] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(arr[i] == 0 || arr[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%MOD + dp[i-1][x+1])%MOD;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % MOD;
    return ans;
}


int main() {
	FASTIO;
	
	int n, m; cin >> n >> m;
	vi arr(n+1);
	rep(i, 1, n+1) cin >> arr[i];


	cout << calc(n, m, arr);

return 0;
}