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

// O(nlogn)

int lis(vi &arr, int n){
	vi dp(n+1, MOD); // dp[i] = element at which max inc subs of length i ends
	dp[0] = -MOD;

	rep(i, 0, n){
		int j = ub(all(dp), arr[i]) - dp.begin();
		if(dp[j-1] < arr[i] && arr[i] < dp[j])
			dp[j] = arr[i];
	}

	int ans = 0;
	rep(i, 0, n+1)
		if(dp[i] < MOD)
			ans = i;


	return ans;
}


int main() {
	FASTIO;
	int n; cin >> n;
	vi arr(n);
	for(int &x: arr) cin >> x;

	cout << lis(arr, n);

return 0;
}