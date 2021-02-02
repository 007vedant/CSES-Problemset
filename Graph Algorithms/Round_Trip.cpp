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
const int N = 1e5+5;

vi adj[N];
vi par(N, -1);
vector<bool> vis(N, 0);
int n, m, st, en;

bool dfs(int u, int p) {
	vis[u] = 1;
	par[u] = p;

	for(auto v: adj[u]){
		if(v == p) continue;
		if(vis[v]) {
			st = v;
			en = u;
			return true;
		}
		if(!vis[v])
			if(dfs(v, u))
				return true;
	}

	return false;
}

bool cycle_detection() {
	rep(i, 1, n+1) {
		if(!vis[i])
			if(dfs(i, -1))
				return true;
	}
	return false;
}

void calc() {
	cin >> n >> m;
	int a, b;
	rep(i, 0, m) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bool ans = cycle_detection();
	if(!ans) {
		cout << "IMPOSSIBLE";
		return;
	}

	vi cycle;
	cycle.pb(en);
	int tmp = en;
	while(tmp != st) {
		cycle.pb(par[tmp]);
		tmp = par[tmp];
	}
	cycle.pb(en);

	cout << sz(cycle) << endl;
	for(int x: cycle) cout << x << " ";


}

int main() {
	FASTIO;
	calc();

return 0;
}