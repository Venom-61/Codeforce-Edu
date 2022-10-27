#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int grid[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            grid[i][j];
        }
    }

    // dp[i][j] -> no. of paths from (i,j) to (n,n)
    int dp[n + 1][n + 1];
    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if(i == n and j == n)
                dp[n][n] = 1;
            else {
                int opt1 = (i == n) ? 0 : dp[i + 1][j];
                int opt2 = (j == n) ? 0 : dp[i][j + 1];
                dp[i][j] = (opt1 + opt2) % mod;
                if(grid[i][j] == '*') {
                    dp[i][j] = 0;
                }
            }
        }
    }
    if(grid[n][n] == '*') 
        cout << "0\n";
    else 
        cout << dp[1][1] << "\n";

    return 0;
}
