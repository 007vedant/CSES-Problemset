#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

ll expo(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}



int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n; cin >> n;
	cout << expo(2, n) << endl;

return 0;
}