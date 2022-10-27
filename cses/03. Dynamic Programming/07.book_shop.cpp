#include<bits/stdc++.h>
using namespace std;

// Book shop

typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int i = 1; i <= n; i++) cin >> price[i];
    for(int i = 1; i <= n; i++) cin >> pages[i];


    // dp[i][j] -> no. of pages can be bought from i books and j money
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else {
                int opt1 = (i == 1) ? 0 : dp[i - 1][j];
                int opt2 = (price[i] > j) ? 0 : pages[i] + dp[i - 1][j - price[i]];
                dp[i][j] = max(opt1, opt2);
            }

        }
    }
    cout << dp[n][x] << "\n";

    return 0;
}
