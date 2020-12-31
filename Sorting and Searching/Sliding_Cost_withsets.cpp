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
int n, k;
Tree tt;
vi a(n);


int main() {
    FASTIO;
    
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, k) tt.ins(a[i]);

    ll prev_m = *tt.find_by_order((k + 1) / 2 - 1);

    ll ans = 0;

    rep(i, 0, k) ans += abs(a[i] - prev_m);
    cout << ans;

    rep(i, 0, n-k) {
        tt.erase(tt.find_by_order(tt.order_of_key(a[i])));
        tt.insert(a[i + k]);

        ll curr_m = *tt.find_by_order((k + 1)/ 2 - 1);
        ans += abs(curr_m - a[i + k]) - abs(prev_m - a[i]);

        //if k is even, subtract extra term

        if (k % 2 == 0) ans -= (curr_m - prev_m);
        // update mid
        prev_m = curr_m;
        cout << " " << ans;
    }
    cout << endl;

return 0;
}