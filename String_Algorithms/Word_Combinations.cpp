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
// #define ins insert

const int MOD = 1e9+7;
const int N = 2e5+5;

template<int N> struct Trie {
	int next[N][26];
	int l_n = 0;

	bool pre[N];

	void ins(string str){
		int curr = 0;
		for(auto &c: str){
			if(!next[curr][c-'a'])
				next[curr][c-'a'] = ++l_n;

			curr = next[curr][c-'a'];
		}
		pre[curr] = true;
	}
	
};


Trie<1000005> T;
int k;
string str;

ll ways[5005];

int main() {
	FASTIO;

	cin >> str >> k;

	rep(i, 0, k){
		string s; cin >> s;
		T.ins(s);
	}

	ways[0] = 1;
	rep(i, 0, sz(str)){
		int curr = 0;
		rep(j, i, sz(str)){
			curr = T.next[curr][str[j] - 'a'];
			if(!curr) break;
			if(T.pre[curr]){
				ways[j+1] = (ways[j+1] + ways[i])%MOD;
			}
		}
	}

	cout << ways[sz(str)];




	

return 0;
}