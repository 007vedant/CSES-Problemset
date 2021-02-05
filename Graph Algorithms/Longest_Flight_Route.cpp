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

// longest path in DAG using toposort and DP

const int MOD = 1e9+7;
const int N = 2e5+5;


vi topo_sort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;

    for(auto li: gr) for(auto x: li) indeg[x]++;
    queue<int> q;
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
    while (!q.empty()) {
        int i = -q.front();
        ret.pb(i);
        q.pop();
        for(auto x: gr[i])
        if (--indeg[x] == 0) q.push(-x);
    }
    return ret;
}

int main() {
    FASTIO;
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+1);
    while (m--) {
        int a, b;
        cin >> a >>b;
        g[a].push_back(b);
    }
    vi o = topo_sort(g), dp(n+1), p(n+1);

    dp[1]=1;

    for(int i: o) for(int j: g[i])
    if (dp[i] && dp[i]+1>dp[j])
        dp[j]=dp[i]+1, p[j]=i;

    int d=dp[n];

    if (!d) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << d << "\n";

    vi ans;

    for (int i=n; i; i=p[i])
        ans.push_back(i);

    rep(i, 0, d)
        cout  << ans[d-1-i] << " \n"[i==d-1];

    return 0;
}