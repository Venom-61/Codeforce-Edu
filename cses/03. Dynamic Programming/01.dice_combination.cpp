#include<bits/stdc++.h>
using namespace std;

// Dice combination
 
const int mod = 1e9 + 7;
 
int32_t main() {
	int n;
	cin >> n;
 
	// dp[x] -> return the number of ways to construct x 
    vector<int> dp(n);
	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=6; j++) {
			if(i - j >= 0)
				(dp[i] += dp[i-j]) %= mod;
		}
	}
	cout << dp[n] << endl;

    return 0;
}
