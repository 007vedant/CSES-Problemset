#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
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


const ll MOD = 1e9+7;
const int N = 1e6+6;

// combinatorics - C(n+r-1, r-1)
// modular inverse
        
ll fact[N], invf[N];

ll binexp(ll a, ll n){
    a %= MOD;
    ll res = 1;
    while(n > 0){
        if(n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}


int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    vector<ll> f(n+m, 1);

    rep(i, 1, n+m) f[i] = f[i-1] * i % MOD;

    ll ans = f[n+m-1] * binexp(f[n-1], MOD-2) % MOD;

    ans = ans * binexp(f[m], MOD-2) % MOD;
    cout << ans;
    return 0;

    

return 0;
}