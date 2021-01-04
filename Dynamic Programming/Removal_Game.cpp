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
#define repr(i, a, b) for(int i = a; i <= (b); ++i)
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

vector<vl> dp(5001, vl(5001, 0));


int main() {
	FASTIO;
	
	int n; cin >> n;
	vi num(n);
	for(auto &x: num) cin >> x;

	rep(l, 1, n+1) {
		for(int i=0; i+l<=n; i++){
			int j = i + l - 1;     // defining array lengths
			ll c1, c2, c3;

			// choices for second player
			c1 = (i+2 <= j) ? dp[i+2][j] : 0;
			c2 = (i+1 <= j-1) ? dp[i+1][j-1]: 0;
			c3 = (i <= j-2) ? dp[i][j-2] : 0;

			dp[i][j] = max(num[i] + min(c1, c2), num[j] + min(c2, c3));
		}
	}

	cout << dp[0][n-1];


return 0;
}