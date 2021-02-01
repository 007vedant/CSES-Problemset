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

vi adj[100005];
vi conns;
vector<bool> vis(N, 0);
int n, m, cmps = 0; // finding connected components

void dfs(int i) {
	vis[i] = 1;
	for(auto e: adj[i]){
		if(!vis[e])
			dfs(e);
	}
}

void calc() {
	cin >> n >> m;
	int a, b;
	rep(i, 0, m){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	rep(i, 1, n+1) {
		if(!vis[i]){
			cmps++;
			conns.pb(i);
			dfs(i);
		}
	}

	cout << cmps - 1 << "\n";
	int f = conns[0];
	rep(i, 1, cmps) {
		int s = conns[i];
		cout << f << " " << s << "\n";
		f = s;
	}
}


int main() {
	FASTIO;
	calc();

return 0;
}