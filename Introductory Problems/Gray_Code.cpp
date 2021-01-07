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
typedef vector<string> vs;

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

vs grayCode(int n){
	if(n <= 0) return {"0"};
	if(n == 1) return {"0", "1"};

	vs rec = grayCode(n-1);
	vs ans;

	rep(i, 0, sz(rec)){
		string s = rec[i];
		ans.pb("0"+s);
	}

	repr(i, sz(rec)-1, 0){
		string s = rec[i];
		ans.pb("1"+s);
	}

	return ans;
}


int main() {
	FASTIO;

	int n; cin >> n;
	vs ans = grayCode(n);

	for(auto s: ans) cout << s << endl;

	

return 0;
}