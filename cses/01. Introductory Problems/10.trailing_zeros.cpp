#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

// Trailing Zeros
 
void solve() {
	int n, ans=0;
	cin >> n;
 
	while(n > 0) {
		n /= 5;
		ans += n;
	}
	cout << ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
 
	solve();
}