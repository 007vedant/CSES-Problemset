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

int n;
vi ans(N);
vi treee[N];

void dfs(int src) {
    ans[src] = 1;
    for(int ch: treee[src]) {
        dfs(ch);
        ans[src] += ans[ch];
    }
}


int main() {
    FASTIO;
    cin >> n;
    rep(i, 2, n+1){
        int x; cin >> x;
        treee[x].pb(i);
    }

    dfs(1);
    rep(i, 1, n+1) cout << ans[i]-1 << ' ';
    

return 0;
}