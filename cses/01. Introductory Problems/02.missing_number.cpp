#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

// missing number
 
int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		ll x;
		cin >> x;
		sum += x;
	}
	ll ans = n * (n + 1) / 2;
	cout << ans - sum;
}