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


int main() {
	FASTIO;

	int n, x, y, curr = 0, ans = 0;
	vector<pair<int, int>> arr;
	cin >> n;
	rep(i, 0, n){

		cin >> x >> y;
		arr.pb(mp(x, y));
	}

	auto comp = [](pi &a, pi &b){return a.s < b.s ;};
	sort(all(arr), comp);

	for (auto ele : arr)
	{
		if (ele.f >= curr)
		{
			curr = ele.s;
			ans++;
		}
	}
	cout << ans;

return 0;
}