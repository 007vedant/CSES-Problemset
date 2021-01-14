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

struct node
{
	ll sum;
	ll setVal;
	ll inc;
	bool setvalid;

	node() {
		sum = 0;
		setvalid = 0;
		inc = 0;
	}

	void reset() {
		setvalid = inc = 0;
	}
	
};

int arr[N];
node seg[4*N];

void build(int nn, int lo, int hi) { // nn = node number
	if(lo == hi){
		seg[nn].sum = arr[lo];
		return;
	}
	int mid = (lo + hi)/2;
	build(2*nn+1, lo, mid);
	build(2*nn+2, mid+1, hi);

	seg[nn].sum = seg[2*nn+1].sum + seg[2*nn+2].sum;
}

void compose(int par, int child) {
	if(seg[par].setvalid) {
		seg[child].setvalid = 1;
		seg[child].setVal = seg[par].setVal;
		seg[child].inc = seg[par].inc;
	}
	else
		seg[child].inc += seg[par].inc;
}

void applyAggr(int nn, int lo, int hi) {
	if(seg[nn].setvalid)
		seg[nn].sum = (hi-lo+1)*seg[nn].setVal;

	seg[nn].sum += (hi-lo+1)*seg[nn].inc;

	if(lo != hi) {
		compose(nn, 2*nn+1);
		compose(nn, 2*nn+2);
	}

	seg[nn].reset();
}

void incUpdate(int nn, int lo, int hi, int l, int r, int x) {
	if(hi < l || r < lo) return;

	if(l <= lo && r >= hi) {
		seg[nn].inc += x;
		return;
	}

	applyAggr(nn, lo, hi);
	int mid = (lo+hi)/2;
	incUpdate(2*nn+1, lo, mid, l, r, x);
	incUpdate(2*nn+2, mid+1, hi, l, r, x);
	applyAggr(2*nn+1, lo, mid);
	applyAggr(2*nn+2, mid+1, hi);

	seg[nn].sum = seg[2*nn+1].sum + seg[2*nn+2].sum;

}

void setUpdate(int nn, int lo, int hi, int l, int r, int x) {
	if(hi < l || r < lo) return;

	if(l <= lo && r >= hi) {
		seg[nn].setvalid = 1;
		seg[nn].setVal = x;
		seg[nn].inc = 0;
		return;
	}

	applyAggr(nn, lo, hi);
	int mid = (lo+hi)/2;
	setUpdate(2*nn+1, lo, mid, l, r, x);
	setUpdate(2*nn+2, mid+1, hi, l, r, x);
	applyAggr(2*nn+1, lo, mid);
	applyAggr(2*nn+2, mid+1, hi);

	seg[nn].sum = seg[2*nn+1].sum + seg[2*nn+2].sum;
}



ll query(int nn, int lo, int hi, int l, int r) {
	if(hi < l || r < lo) return 0;

	applyAggr(nn, lo, hi);
	if(l <= lo && r >= hi) return seg[nn].sum;

	int mid = (lo+hi)/2;
	ll lft = query(2*nn+1, lo, mid, l, r);
	ll rht = query(2*nn+2, mid+1, hi, l, r);

	return lft+rht;
}


int main() {
	FASTIO;

	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> arr[i];

	build(0, 0, n-1);

	while(q--) {
		int t, a, b, x;
		cin >> t;
		if(t == 1) {
			cin >> a >> b >> x;
			a--, b--;
			incUpdate(0, 0, n-1, a, b, x);
		}
		else if(t == 2) {
			cin >> a >> b >> x;
			a--, b--;
			setUpdate(0, 0, n-1, a, b, x);
		}
		else{
			cin >> a >> b;
			a--, b--;
			cout << query(0, 0, n-1, a, b) << "\n";
		}
	}
	

return 0;
}