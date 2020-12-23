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

int n, k;
Tree ttree;


int main() {
	FASTIO;

	cin >> n >> k;
	vi arr(n);
	for(auto &x: arr) cin >> x;
	rep(i, 0, k) ttree.ins(arr[i]);
	
	cout << *ttree.find_by_order((k+1)/2 - 1);
	rep(i, 0, n-k){
		ttree.erase(ttree.find_by_order(ttree.order_of_key(arr[i])));
		ttree.ins(arr[i+k]);

		cout << " " << *ttree.find_by_order((k+1)/2 - 1);
	}

	

return 0;
}