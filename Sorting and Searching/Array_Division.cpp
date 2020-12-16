#include<bits/stdc++.h>
using namespace std;

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

bool check(vl &arr, ll mid, int k){
	int sub = 0; ll sum = 0;
	rep(i, 0, sz(arr)){
		if(arr[i] > mid)
			return false;
		if(sum + arr[i] > mid){
			++sub;
			sum = 0;
		}
		sum += arr[i];
	}
	if(sum) ++sub;

	return sub <= k;
}


int main() {
	FASTIO;

	int n, k; cin >> n >> k;

	vl arr(n);
	for(auto &x: arr) cin >> x;

	ll lo = 0, hi = (ll) 1e18, ans = 0;
	
	while(lo <= hi){
		ll mid = (lo + hi)/2;
		if(check(arr, mid, k)){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	
	cout << ans;

return 0;
}