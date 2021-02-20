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

void solve(vi &code) {
    vi deg(n+1, 1); deg[0] = 0;
    for(int x: code) deg[x]++;

    int ptr = 0;
    while(deg[ptr] != 1)
        ptr++;

    int leaf = ptr;
    int ans[2];
    for(int v: code) {
        ans[0] = leaf, ans[1] = v;
        sort(ans, ans+2);
        cout << ans[0] << " " << ans[1] << "\n";
        if(--deg[v] == 1 && v < ptr)
            leaf = v;
        else {
            ptr++;
            while(deg[ptr] != 1)
                ptr++;

            leaf = ptr;
        }
    }

    cout << leaf << " " << n;
}


int main() {
    FASTIO;
    cin >> n;
    vi code(n-2);
    for(int &x: code) cin >> x;

    solve(code);

return 0;
}