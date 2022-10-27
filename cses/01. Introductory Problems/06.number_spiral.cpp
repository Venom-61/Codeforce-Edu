#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define nline "\n"
 
// Number Spiral 
 
void solve() {
	ll r, c;
	cin >> r >> c;
	ll ans = 0;
	ll z = max(r, c);
	ll z2 = (z - 1) * (z - 1);
	if (z % 2 == 0) {
		if (z == c) {
			ans = z2 + r;
		} else {
			ans = z2 + 2 * z - c;
		}
	} else {
		if (z == r) {
			ans = z2 + c;
		} else {
			ans = z2 + 2 * z - r;
		}
	}
	cout << ans << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int tt;
	cin >> tt;
	while(tt--) 
		solve();
	return 0;
}