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

// bipartite / 2 color

vi adj[N];
vi color(N, 0);
vector<bool> vis(N, 0);
int n, m;

bool dfs(int u, int c, int par) {
	vis[u] = 1;
	color[u] = c;

	for(auto v: adj[u]){
		if(v == par) continue;
		if(color[v] == 0)
			if(!dfs(v, color[u]^3, u))
				return false;
		if(color[v] == color[u])
			return false;
	}

	return true;
}

bool coloring() {
	rep(i, 1, n+1) {
		if(!vis[i])
			if(!dfs(i, 1, -1))
				return false;
	}
	return true;
}

void calc() {
	cin >> n >> m;
	int a, b;
	rep(i, 0, m) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bool ans = coloring();
	if(!ans) {
		cout << "IMPOSSIBLE";
		return;
	}

	rep(i, 1, n+1) {
		cout << color[i] << " ";
	}


}

int main() {
	FASTIO;
	calc();

return 0;
}