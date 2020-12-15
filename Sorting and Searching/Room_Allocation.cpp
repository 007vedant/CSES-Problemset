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
#define repr(i, a, b) for(int i = a; i > (b); i--)
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
int n, ans[N];

vector<pair<pi, int> > times(N);


int main() {
	FASTIO;

	cin >> n; times.resize(n);
	rep(i, 0, n){
		cin >> times[i].f.f >> times[i].f.s;
		times[i].s = i;
	}

	sort(all(times));

	int lastroom = 0, totalrooms = 0;
	priority_queue<pi> pq;

	rep(i, 0, n){
		if(pq.empty()){
			lastroom++;
			pq.push(mp(-times[i].f.s, lastroom));
			ans[times[i].s] = lastroom;
		}
		else{
			auto curr_min = pq.top();
			if(-curr_min.f < times[i].f.f){
				pq.pop();
				pq.push(mp(-times[i].f.s, curr_min.s));
				ans[times[i].s] = curr_min.s;
			}
			else{
				lastroom++;
				pq.push(mp(-times[i].f.s, lastroom));
				ans[times[i].s] = lastroom;
			}
		}

		totalrooms = max(totalrooms, sz(pq));
	}

	cout << totalrooms << "\n";
	rep(i, 0, n) cout << ans[i] << " ";
	

return 0;
}