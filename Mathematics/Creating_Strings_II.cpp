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
const int N = 1e6+6;

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

void preCalc(){

    fact[0] = invf[0] = 1;
    rep(i, 1, N) fact[i] = fact[i-1] * i % MOD;

    invf[N-1] = binexp(fact[N-1], MOD-2);

    rep(i, 1, N) invf[N-i-1] = invf[N-i] * (N-i) % MOD;
}



int main() {
    FASTIO;
    preCalc();

    map<char, int> mp;
    string str; cin >> str;

    for(char c: str) mp[c]++;

    ll ans = fact[str.length()];
    for(auto p: mp)
        ans = ans * invf[p.s] % MOD;

    cout << ans;



return 0;
}