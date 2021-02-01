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

// LDDRRRRRU

int n, m, dist[2500][2500];
char g[2500][2500];
pair<pi, char> par[2500][2500];
pi st, en;
queue<pi> q;

int xdir[4] = {0, 1, 0, -1}, ydir[4] = {1, 0, -1, 0};
string dir = "RDLU";

bool isvalid(pi p) {
	return p.f >= 0 && p.f < n && p.s >= 0 && p.s < m && g[p.f][p.s] != '#';
}

void calc() {
	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			dist[i][j] = MOD;
			cin >> g[i][j];
			if(g[i][j] == 'A') st = {i, j};
			else if(g[i][j] == 'B') en = {i, j};
		}
	}

	dist[st.f][st.s] = 0;
    q.push(st);
    while (sz(q)) {
        pi x = q.front(); q.pop();
        rep(i,0,4) {
            pi X = {x.f+xdir[i],x.s+ydir[i]};
            if (!isvalid(X) || dist[X.f][X.s] != MOD) continue;
            dist[X.f][X.s] = dist[x.f][x.s]+1;
            par[X.f][X.s] = {x,dir[i]};
            q.push(X);
        }
    }
    if (dist[en.f][en.s] == MOD) {
        cout << "NO";
        return;
    }
    string z;
    while (en != st) {
        z += par[en.f][en.s].s;
        en = par[en.f][en.s].f;
    }
    cout << "YES\n";
    reverse(all(z));
    cout << sz(z) << "\n";
    cout << z;
}


int main() {
	FASTIO;
	calc();

return 0;
}