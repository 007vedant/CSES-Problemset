#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length(), ans = 0, curr = 1;
	for(int i=1; i<n; i++){
		if(s[i-1] != s[i]){
			ans = max(ans, curr);
			curr = 0;
		}
		curr++;
	}
	ans = max(ans, curr);
	cout << ans;
return 0;
}