#include<bits/stdc++.h>
using namespace std;

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

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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
const int N=2e5+5;


ll binexp(ll a, ll n, ll m){
	a %= m;
    ll res = 1;
    while(n > 0){
        if(n & 1)
        	res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}



int main() {
	FASTIO;

	int t; cin >> t;
	while(t--){
		ll a, b, c; cin >> a >> b >> c;

		// using fermat's lil theorem for B^C and then simplifying the entire A^(B^C) expression

		ll pre = binexp(b, c, MOD-1);

		ll ans = binexp(a, pre, MOD);

		cout << ans << endl;
	}

return 0;
}