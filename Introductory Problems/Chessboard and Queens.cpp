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
const int N=2e5+5;

bool cols[8], ldiag[16], rdiag[16];

void calc(string board[8], int i, int &ans){
	if(i == 8){
		ans++;
		return;
	}
	for(int j=0; j<8; j++){
		if(board[i][j] == '.'){
			if(!cols[j] && !ldiag[i-j+7] && !rdiag[i+j]){
				cols[j] = ldiag[i-j+7] = rdiag[i+j] = true;
				calc(board, i+1, ans);
				cols[j] = ldiag[i-j+7] = rdiag[i+j] = false;
			}
		}
	}
}


int main() {
	FASTIO;

	string board[8];
	int ans = 0;
	for(int i=0; i<8; i++)
		cin >> board[i];


	calc(board, 0, ans);
	cout << ans;

return 0;
}