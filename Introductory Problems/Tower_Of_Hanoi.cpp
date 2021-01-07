#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

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

vector<pair<int, int> > ans;

void ToW(int n, int l, int r, int mid, int &moves){
    if(n == 1){
        moves++;
        ans.pb(mp(l, r));
        return;
    }
    moves++;
    ToW(n-1, l, mid, r, moves);
    ans.pb(mp(l, r));
    ToW(n-1, mid, r, l, moves);
}

int main() {
    int n; cin >> n;
    int moves = 0;

    ToW(n, 1, 3, 2, moves);

    cout << moves << endl;
    for(auto p: ans)
        cout << p.f << " " << p.s << endl;

    
 
return 0;
}