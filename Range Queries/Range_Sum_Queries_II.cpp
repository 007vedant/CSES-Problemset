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
int arr[N];
ll seg[4*N]; 

void build(int ind, int lo, int hi){
	if(lo == hi){
		seg[ind] = arr[lo];
		return;
	}

	int mid = (lo + hi)/2;
	build(2*ind+1,lo, mid);
	build(2*ind+2, mid+1, hi);

	// seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

ll query(int ind, int lo, int hi, int l, int r){
	if(lo >= l && hi <= r)  
		return seg[ind];

	if(lo > r || hi < l)  
		return 0;

	int mid = (lo+hi)/2;
	ll left = query(2*ind+1, lo, mid, l, r);
	ll right = query(2*ind+2, mid+1, hi, l, r);

	return left+right;
}

void update(int ind, int lo, int hi, int pos, int new_val){
	if(lo == hi){
		seg[ind] = new_val;
		return;
	}

	int mid = (lo+hi)/2;
	if(pos <= mid)
		update(2*ind+1, lo, mid, pos, new_val);
	else
		update(2*ind+2, mid+1, hi, pos, new_val);

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int main() {
	FASTIO;
	
	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> arr[i];

	build(0, 0, n-1);


	while(q--){
		int t, a, b; cin >> t >> a >> b;
		if(t == 1) update(0, 0, n-1, a-1, b);
		else{
			cout << query(0, 0, n-1, a-1, b-1) << endl;
		}
	}




return 0;
}