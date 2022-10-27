#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define nline "\n"
 
// Increasing Array
 
void solve() {
	ll n;
	cin >> n;
	ll a[n];
 
	for(ll i=0; i<n; i++) {
		cin >> a[i];
	}
 
	ll ans = 0;
	for(ll i=0; i<n-1; i++) {
		if(a[i] > a[i+1]) {
			ans += a[i] - a[i+1];
			a[i+1] = a[i];
		}
	}
	cout << ans << nline;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
	return 0;
}