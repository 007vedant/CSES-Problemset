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
int seg[4*N];

void build(int k, int l, int r){
	int m, k1, k2;
    
    if (r - l == 1) {
        seg[k] = arr[l];
        return;
    }
    m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
    build(k1, l, m);
    build(k2, m, r);
    seg[k] = seg[k1] < seg[k2] ? seg[k1] : seg[k2];
}

int query(int k, int l, int r, int ql, int qr){
	 int m, q1, q2;
    
    if (qr <= l || r <= ql)
        return MOD;
    if (ql <= l && r <= qr)
        return seg[k];
    m = (l + r) / 2;
    q1 = query(k * 2 + 1, l, m, ql, qr);
    q2 = query(k * 2 + 2, m, r, ql, qr);
    return q1 < q2 ? q1 : q2;
}


int main() {
	FASTIO;

	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> arr[i];

	build(0, 0, n);

	while(q--){
		int a, b; cin >> a >> b;
		cout << query(0, 0, n, a-1, b) << endl;
	}
	

return 0;
}