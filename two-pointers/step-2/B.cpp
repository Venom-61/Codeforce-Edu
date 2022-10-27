#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Shortest Segment with sum atleast s

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, res = INT_MAX; 
    ll x = 0; 
    for(int r = 0; r < n; r++) {
        x += a[r];
        while(x >= s) {
            x -= a[l++];
        } 

        // ? l .. r largest bad segments
        // cout << l << " " << r << " " << x << endl;
    
        // ?  l - 1 .. r segments are good
        if(l > 0) {
            // cout << l - 1 << " " << r << " " << x << endl;
            res = min(res, r - (l - 1) + 1);
        }
    }

    if(res == INT_MAX)
        cout << "-1\n";
    else 
        cout << res << "\n";

    return 0;
} 
