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
typedef greater<pl> gpl;
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

// single source shortest path

int n, m;
vpl adj[N];
vl dist(N, 1e17);
priority_queue<pl, vpl, gpl> pq;

void dijsktra() {
	dist[1] = 0;
	pq.push({0, 1});

	while(!pq.empty()) {
		ll u = pq.top().s;
		ll d = pq.top().f;

		pq.pop();

		if(dist[u] < d) continue;
		for(auto p: adj[u]) {
			ll v = p.f;
			ll c = p.s;

			if(dist[v] <= c + d) continue;
			else {
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
		}
	}
}


void calc() {
	cin >> n >> m;
	int a, b, d;
	rep(i, 0, m) {
		cin >> a >> b >> d;
		adj[a].pb({b, d});
	}

	dijsktra();

	rep(i, 1, n+1) cout << dist[i] << " ";
}

int main() {
	FASTIO;
	calc();
	

return 0;
}