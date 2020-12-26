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

vi manacheralgo(string str){
	string sr = "$";
	for(char c: str) sr += c, sr += "@";
	sr[sr.length()-1] = '!';

	vi ans(sr.length() - 1);
	int lo = 0, hi = 0;

	rep(i, 1, sr.length()-1){
		ans[i] = min(hi-i, ans[hi-i+lo]);
		while(sr[i-ans[i]-1] == sr[i+ans[i]+1])
			ans[i]++;

		if(i+ans[i] > hi)
			lo = i-ans[i], hi = i+ans[i];
	}

	ans.erase(ans.begin());
	rep(i, 0, sz(ans))
		if((i&1) == (ans[i]&1))
			ans[i]++;


	return ans;
}


int main() {
	FASTIO;

	string str;
	cin >> str;

	vi arr = manacheralgo(str);

	pi ans = {-1, -1};

	rep(i, 0, sz(arr))
		ans = max(ans, {arr[i], i});

	cout << str.substr((ans.s+1)/2 - ans.f/2, ans.f);
	

return 0;
}