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
bool vis[2005][2005];
char grid[2005][2005];
int n, m;

bool isvalid(int i, int j){
	if(i<0 || i>=n || j<0 || j>=m) return false;
	if(vis[i][j] == true || grid[i][j] == '#') return false;
	return true;
}

void dfs(int i, int j){
	vis[i][j] = true;
	if(isvalid(i-1, j))
		dfs(i-1, j);

	if(isvalid(i+1, j))
		dfs(i+1, j);

	if(isvalid(i, j+1))
		dfs(i, j+1);

	if(isvalid(i, j-1))
		dfs(i, j-1);
}



int main() {
	FASTIO;

	cin >> n >> m;
	rep(i, 0, n)
		rep(j, 0, m)
			cin >> grid[i][j];



	int ans = 0;
	
	rep(i, 0, n){
		rep(j, 0, m){
			if(grid[i][j] == '.' && vis[i][j] == false){
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans;

	

return 0;
}