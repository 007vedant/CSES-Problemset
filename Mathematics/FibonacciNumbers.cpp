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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = a; i <= (b); ++i)
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

ll p, q, r ,s;

// Algorithm - Fast Doubling for Fibonacci Numbers
// Reference - 
          //  F(2n) = F(n)[2*F(n+1) - F(n)]
          //  F(2n+1) = F(n)^2 + F(n+1)^2


void fast_fibonacci(ll n, ll ans[]){
	if(n == 0){
		ans[0] = 0;
		ans[1] = 1;
		return;
	}

	fast_fibonacci(n/2, ans);

	p = ans[0];								// F(n)
	q = ans[1];								// F(n+1)

	r = 2*q - p;

	if(r < 0) r += MOD;

	r = (p * r) % MOD;						// F(2n)
	s = (p*p + q*q) % MOD;					// F(2n+1)

	if(n % 2 == 0){
		ans[0] = r;
		ans[1] = s;
	}
	else{
		ans[0] = s;
		ans[1] = r+s;
	}
}


int main() {
	FASTIO;

	ll n; cin >> n;

	ll ans[2] = {0};

	fast_fibonacci(n, ans);

	cout << ans[0];
	

return 0;
}