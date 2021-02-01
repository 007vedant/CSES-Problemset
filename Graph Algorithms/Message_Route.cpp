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
queue<int> q;
vi dist(N, MOD), par(N);
int n, m;


void bfs() {
	q.push(1);
	while(sz(q)) {
		int u = q.front(); q.pop();
		for(auto e: adj[u]) {
			if(dist[e] == MOD){
				dist[e] = dist[u] + 1;
				par[e] = u;
				q.push(e);
			}
		}
	}
}

void calc() {
	cin >> n >> m;
	int a, b;
	rep(i, 0, m) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dist[1] = 0;
	bfs();

	if(dist[n] == MOD) {
		cout << "IMPOSSIBLE";
		return;
	}

	cout << dist[n] + 1<< "\n";
	vi ans = {n};
	while(ans.back() != 1)
		ans.pb(par[ans.back()]);

	reverse(all(ans));
	for(int a: ans) cout << a << " ";

}

int main() {
	FASTIO;
	calc();
	

return 0;
}