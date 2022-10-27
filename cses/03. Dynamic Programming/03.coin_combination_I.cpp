#include<bits/stdc++.h>
using namespace std;

// Coin combination - I
 
const int mod = 1e9 + 7;
 
int32_t main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int &x : arr) cin >> x;
 
	// dp[x] -> number of ways to make x 
	vector<int> dp(x, 0);
	dp[0] = 1;
	for(int i = 1; i <= x; i++) {
		for(auto c : coins) {
			if(i - c >= 0) 
				(dp[i] += dp[i - c]) %= mod;
		}
	}
	cout << dp[x] << endl;

    return 0;
}
