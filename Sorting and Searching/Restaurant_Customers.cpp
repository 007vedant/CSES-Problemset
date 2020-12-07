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


int main() {
	FASTIO;

	int n, ans = 0, curr = 0;
	vector<pair<int, bool>> arr;

	cin >> n;

	while (n--){
		int x, y;
		cin >> x >> y;

		arr.pb(mp(x, true));
		arr.pb(mp(y, false));

	}

	sort(all(arr));

	rep(i, 0, sz(arr)){

		curr += arr[i].s ? 1 : -1;
		ans = max(ans, curr);
	}

	cout << ans;
	

return 0;
}