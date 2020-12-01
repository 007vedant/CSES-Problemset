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

void calc() {
	int n; cin >> n;
	int wts[n];
	ll tw = 0;

	for(int i=0; i<n; i++){
		cin >> wts[i];
		tw += wts[i];
	}

	ll ans = INT_MAX;
	for(int i=0; i<(1<<n); i++){
		ll csum = 0;
		for(int j=0; j<n; j++){
			if(1<<j & i)
				csum += wts[j];
		}



		ans = min(ans, abs(tw - csum - csum));

	}

	cout << ans;
}


int main() {
	FASTIO;

	calc();

return 0;
}