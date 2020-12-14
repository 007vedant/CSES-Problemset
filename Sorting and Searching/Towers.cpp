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

int n, x, c;


int main() {
	FASTIO;
	
	cin >> x >> n;
	
	set<int> pos;
	multiset<int> dist;
	pos.insert({0, x});
	dist.insert(x);

	rep(i, 0, n){
		cin >> c;
		auto rt = pos.upper_bound(c);
		auto lt = rt;
		lt--;

		int v1 = *rt;
		int v2 = *lt;

		dist.erase(dist.find(v1 - v2));
		pos.insert(c);
		dist.insert(v1 - c);
		dist.insert(c - v2);

		auto it = dist.rbegin();
		// it--;
		cout << *it << " ";
	}
	

return 0;
}