#include<bits/stdc++.h>
using namespace std;

bool valid(string temp, string draw, int K){
	int c = 0, skips = 0;
	for(int i=0; i<draw.length(); i++){
		if(s[c] == 'o' || s[c] == 'a'){
			if(draw[i] == 'o' || draw[i] == 'a')
				c++;
			else
				skips++;
		}
		else if(s[c] == draw[i]) c++;
		else
			skips++;
	}
	if(skips <= K && (c == temp.length() || c == temp.length() - 1))
		return true;
	return false;
}

itn calc(vector<string> &tick, string draw, int K) {
	int ans = 0;
	for(string s: tick)
		if(isvalid(s, draw, K))
			ans++;


	return ans;
}


int main() {
	int n;
	string draw; cin >> draw;
	vector<string> tick;
	for(auto &s: tick) cin >> s;
	int K; cin >> K;

	cout << calc(tick, draw, K);

return 0;
}