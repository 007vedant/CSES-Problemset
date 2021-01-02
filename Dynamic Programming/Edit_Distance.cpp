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
vector<vi> dp(2, vi(5001, 0));

int editDistance(string s1, string s2){
	int n = s1.length(), m = s2.length();

	rep(i, 0, n+1)
		dp[0][i] = i;


	rep(i, 1, m+1){
		rep(j, 0, n+1){
			if(j == 0)
				dp[i%2][j] = i;

			else if(s1[j-1] == s2[i-1])          // same char
				dp[i%2][j] = dp[(i-1)%2][j-1];

			else
				dp[i%2][j] = 1 + min(dp[(i-1)%2][j], min(dp[i%2][j-1], dp[(i-1)%2][j-1]));
		}
	}

	return dp[m%2][n];
}

int main() {
	FASTIO;

	string s1, s2;
	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2);



return 0;
}