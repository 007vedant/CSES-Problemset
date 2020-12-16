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

	int n, x; cin >> n >> x;
	vpi nums(n);

	rep(i, 0, n){
		cin >> nums[i].f;
		nums[i].s = i+1;
	}

	sort(all(nums));

	rep(i, 0, n){
		int j = i+1;
		int k = n-1;

		int curr = x - nums[i].f;

		while(j < k){
			if(nums[j].f + nums[k].f == curr){
				cout << nums[i].s << " " << nums[j].s << " " << nums[k].s;
				return 0;
			}
			else if(nums[j].f + nums[k].f > curr)
				k--;
			else
				j++;
		}
	}

	cout << "IMPOSSIBLE";
	

return 0;
}