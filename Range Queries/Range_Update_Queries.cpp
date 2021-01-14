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

int a[N];
ll seg[4*N], lazy[4*N];

void build(int ind, int lo, int hi) {
	if(lo == hi) { // leaf
		seg[ind] = a[lo];
		return;
	}
	int mid = (lo + hi)/2;
	build(2*ind+1, lo, mid);
	build(2*ind+2, mid+1, hi);

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void lazyupdate(int ind, int lo, int hi, int l, int r, int val) {
	if(lazy[ind] != 0) {
		seg[ind] += (hi-lo+1)*lazy[ind];

		if(lo != hi) { // not leaf
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
		}

		lazy[ind] = 0; // reset
	}

	if(lo > hi || hi < l || lo > r) return;

	if(lo >= l && hi <= r) {
		seg[ind] += (hi-lo+1)*val;
		if(lo != hi) {
			lazy[2*ind+1] += val;
			lazy[2*ind+2] += val;
		}

		return;
	}

	int mid = (hi+lo)/2;
	lazyupdate(2*ind+1, lo, mid, l, r, val);
	lazyupdate(2*ind+2, mid+1, hi, l, r, val);

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

ll query(int ind, int lo, int hi, int l, int r) {
	if(lazy[ind] != 0) {
		seg[ind] += (hi-lo+1)*lazy[ind];
		if(lo != hi) {
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
		}

		lazy[ind] = 0; //reset
	}

	if(lo > hi || hi < l || lo > r) return 0;

	if(lo >= l && hi <= r) return seg[ind];

	int mid = (hi+lo)/2;
	ll lft = query(2*ind+1, lo, mid, l, r);
	ll rht = query(2*ind+2, mid+1, hi, l, r);

	return lft+rht;
}


int main() {
	FASTIO;

	int n, q; cin >> n >> q;

	rep(i, 0, n) cin >> a[i];

	build(0, 0, n-1);

	while(q--) {
		int t, a, b, k;
		cin >> t;
		if(t == 1) {
			cin >> a >> b >> k;
			a--, b--;
			lazyupdate(0, 0, n-1, a, b, k);
		}
		else {
			cin >> k;
			k--;
			cout << query(0, 0, n-1, k, k) << "\n";
		}
	}
	

return 0;
}