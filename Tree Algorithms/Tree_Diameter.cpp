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
#define INF    0x3f3f3f3f3f3f3f3fLL


const int MOD = 1e9+7;
const int N = 2e5+5;

vi adj[N];
int f[N], g[N];
int ans;

// f[v] = longest path in subtree of v
// g[v] = longest path in subtree of v which passes through v

void dfs(int node, int par) {
	vi children;
	for(int ch: adj[node]) {
		if(ch != par) {
			dfs(ch, node);
			f[node] = max(f[node], 1 + f[ch]);
			children.pb(f[ch]);
		}
	}

	ans = max(ans, f[node]);
	sort(all(children));

	if(sz(children) >= 2) {
		g[node] = 2 + children[sz(children)-1] + children[sz(children)-2];
		ans = max(ans, g[node]);
	}
}


int main() {
	FASTIO;

	int n; cin >> n;
	rep(i, 1, n) {
		int x, y; 
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}


	dfs(1, -1);
	cout << ans << endl;
	

return 0;
}