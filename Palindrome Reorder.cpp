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

int cnt = 0;
bool ch[26];

void calc(string s){
	string ans = "";
	for(char c: s){
		if(!ch[c-'A']){
			ch[c-'A'] = true;
			cnt++;
		}
		else{
			ans += c;
			ch[c-'A'] = false;
			cnt--;

		}
	}

	if(cnt >= 2){
		cout << "NO SOLUTION";
		return;
	}
	cout << ans;
	for(char c='A'; c <= 'Z'; c++){
		if(ch[c-'A'])
			cout << c;
	}
	reverse(all(ans));
	cout << ans;


}


int main() {
	FASTIO;

	string s; cin >> s;
	int n = s.length();

	calc(s);

return 0;
}