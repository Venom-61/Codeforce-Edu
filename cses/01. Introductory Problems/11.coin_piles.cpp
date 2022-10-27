#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

// Coin Piles
 
void solve() {
	ll a, b;
	cin >> a >> b;
	if((a + b) % 3 != 0 or a > 2 * b or b > 2 * a) 
		cout << "NO" << endl;
	else 
		cout << "YES" << endl;
}
 
int main() {
	int tc;
	cin >> tc; 
	while(tc--) {
		solve();
	}
}