#include<bits/stdc++.h>
using namespace std;

#define ll long long

void calc() {
	ll n; cin >> n;

	while(n > 1){
		cout << n << " ";
		if(n % 2 == 0)
			n /= 2;
		else
			n = n*3 + 1;
	}
	cout << n << " ";
}

int main(){
	calc();
}