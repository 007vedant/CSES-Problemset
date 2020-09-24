#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll total = 0, m = arr[0];
    for (ll i = 1; i < n; i++)
    {
        total += max(0LL, m - arr[i]);
        m = max(m, arr[i]);
    }
    cout << total;
    return 0;
}