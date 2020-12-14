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

// excellent question on binary search


int main() {
	FASTIO;

	int n; ll p; cin >> n >> p;
	vl times(n);

	for(auto &x: times) cin >> x;

	ll lo = 0, hi = 1e18, ans = 0;
	
	while(lo <= hi) {
		ll mid = lo + (hi - lo)/2;
		ll curr_total = 0;

		rep(i, 0, n){
			curr_total += mid/times[i];
			if(curr_total >= p) break;
		}
		
		if(curr_total >= p){
			ans = mid;
			hi = mid - 1;
		}
		else{
			lo = mid+1;
		}
	}

	cout << ans;


	

return 0;
}