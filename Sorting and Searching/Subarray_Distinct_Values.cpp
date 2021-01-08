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

ll atMostK(vi &arr, int n, int k)
{
 
    ll ans = 0;
 
    int l = 0;
 
    int r = 0;
 
    map<int,int> map;
    while (r < n) {
 
        if (map.find(arr[r])==map.end())
            map[arr[r]]=0;
        map[arr[r]]++;
 
        while (map.size() > k) {
            map[arr[l]]= map[arr[l]] - 1;
            if (map[arr[l]] == 0)
                map.erase(arr[l]);
            l++;
        }
 
        ans += r - l + 1;
        r++;
    }
    return ans;
}


int main() {
	FASTIO;
	int n, k; cin >> n >> k;
	vi arr(n);
	for(int &x: arr) cin >> x;


	cout << atMostK(arr, n, k);
	

return 0;
}