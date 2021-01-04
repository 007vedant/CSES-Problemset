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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1e9+7;
const int N = 2e5+5;

struct Job
{
	ll s, f, val;
};

bool cmp(Job a, Job b) {
	return a.f < b.f;
}

ll Search(Job arr[], int i) {
	ll lo = 0, hi = i-1;
	while(lo <= hi){
		ll mid = lo + (hi - lo)/2;
		if(arr[mid].f < arr[i].s) {
			if(arr[mid+1].f < arr[i].s)
				lo = mid + 1;
			else
				return mid;
		}
		else{
			hi = mid - 1;
		}
	}

	return -1;
}

int main() {
	FASTIO;

	int n; cin >> n;
	Job arr[n];
	rep(i, 0, n)
		cin >> arr[i].s >> arr[i].f >> arr[i].val;

	sort(arr, arr+n, cmp);

	vl dp(n, 0);
	dp[0] = arr[0].val;

	rep(i, 1, n){
		ll inc = arr[i].val;
		ll prev = Search(arr, i);
		if(prev != -1)
			inc += dp[prev];
		ll exc = dp[i-i];

		dp[i] = max(inc, exc);
	}

	cout << dp[n-1];
	

return 0;
}