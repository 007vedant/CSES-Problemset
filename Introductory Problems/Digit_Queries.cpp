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

int digAtN(ll n) {
  ll len = 1, cnt = 9, start = 1;
  while(n > len * cnt){
     n -= len * cnt;
     cnt *= 10;
     start *= 10;
     len++;
  }
  start += (n - 1) / len;
  string s = to_string(start);
  return s[(n - 1) % len] - '0';
}




int main() {
	FASTIO;
	int q; cin >> q;
	while(q--){
		ll n; cin >> n;
		cout << digAtN(n) << endl;
	}
	

return 0;
}