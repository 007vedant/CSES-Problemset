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

int dp[1000][1000], n;
string grid[1000];

int main() {
	FASTIO;

	cin >> n;
	rep(i, 0, n)
		cin >> grid[i];


	rep(i, 0, n){
		rep(j, 0, n){
			if(grid[i][j] == '.') {

				if(i == 0 && j == 0)
					dp[i][j] = 1;
				else{
					if(i) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
					if(j) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
				}
			}
		}
	}

	cout << dp[n-1][n-1];

return 0;
}