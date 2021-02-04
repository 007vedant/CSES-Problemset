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

// floyd warshall on undirected graph, APSP

int n, m, q;
int u, v;
ll c;
vector<vl> g(505, vl(505, INF));


int main() {
	FASTIO;
	cin >> n >> m >> q;
	rep(i, 1, n+1)
		g[i][i] = 0;

	rep(i, 0, m) {
		cin >> u >> v >> c;
		if (g[u][v] > c)
            g[u][v] = g[v][u] = c;
	}

	// floyd warshall

	rep(k, 1, n+1){
		rep(i, 1, n+1){
			rep(j, 1, n+1) {
				if (g[i][j] > (c = g[i][k] + g[k][j]))
                    g[i][j] = c;
			}
		}
	}

	rep(k, 1, n+1) 
		if (g[k][k] < 0) 
			rep(i, 1, n+1) 
				rep(j, 1, n+1)
        			if (g[i][k] != INF && g[k][j] != INF) g[i][j] = -INF;

	rep(i, 0, q) {
		cin >> u >> v;
		if(g[u][v] == INF)
			g[u][v] = -1;

		cout << g[u][v] << "\n"; 
	}

return 0;
}