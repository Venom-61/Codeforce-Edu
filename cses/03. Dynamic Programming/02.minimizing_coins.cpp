#include<bits/stdc++.h>
using namespace std;

// Minimizing coins

const int mod = 1e9 + 7;
 
int32_t main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(auto &x : coins) cin >> x;
 
	// dp[x] -> no. of minimum coins req. to produce x sum

	vector<int> dp(x+1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= x; i++) {
		for(auto c : coins) {
			if(i - c >= 0)
				dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}
	cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;

    return 0;
}
