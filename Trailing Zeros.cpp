#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll trailz(ll n){
	ll cnt = 0;
	for(int i=5; n/i >= 1; i*=5)
		cnt += n/i;

	return cnt;
}


int main() {
	ll n; cin >> n;
	cout << trailz(n);

return 0;
}