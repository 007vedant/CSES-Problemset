#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define rep(i, a, b) for(int i = a; i < (b); ++i)

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
const int N=1e6+6;

// fermat's little theorem: inv multiplication

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

ll nCr(ll a, ll b){
	return fact[a] * invf[b] % MOD * invf[a-b] % MOD;
}


int main(){
	FASTIO;

	preCalc();

    int t; cin >> t;
    while(t--){
    	int a, b;
    	cin >> a >> b;

    	cout << nCr(a, b) << endl;
    }
}