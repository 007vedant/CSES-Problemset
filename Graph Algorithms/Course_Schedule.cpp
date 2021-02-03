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

// topological sort

int n, m;
vi adj[N];
vi indegree(N, 0);
queue<int> q;
vi ans;

bool toposort(int n) {
	for(auto v: adj)
		for(auto nn: v)
			indegree[nn]++;

	rep(i, 1, n+1)
		if(indegree[i] == 0)
			q.push(i);

	while(!q.empty()) {
		int v = q.front(); q.pop();
		n--;
		ans.pb(v);
		for(auto nn: adj[v]) {
			if(--indegree[nn] == 0)
				q.push(nn);
		}
	}

	return n == 0;

}

void calc() {
	cin >> n >> m;
	int a, b;
	rep(i, 0, m) {
		cin >> a >> b;
		adj[a].pb(b);
	}

	bool ok = toposort(n);
	if(!ok) {
		cout << "IMPOSSIBLE";
		return;
	}

	for(int x: ans) cout << x << " "; 


}


int main() {
	FASTIO;
	calc();
	

return 0;
}