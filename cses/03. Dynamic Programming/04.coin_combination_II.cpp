#include<bits/stdc++.h>
using namespace std;

// Coin Combination - II

typedef long long ll;

const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    vector<int> coins(n + 1);
    for(int i = 1; i <= n; i++) cin >> coins[i];

    // dp[x] -> no. of ways to make sum x
    int dp[n + 1][x + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            if(j == 0) {
                dp[i][j] = 1; 
            } else {
                // if we take it
                int opt1 = (coins[i] > j) ? 0 : dp[i][j - coins[i]];

                // if we don't take it
                int opt2 = (i == 1) ? 0 : dp[i - 1][j];
                dp[i][j] = (opt1 + opt2) % mod;
            }
        }
    }
    cout << dp[n][x] << "\n";

    return 0;
}
