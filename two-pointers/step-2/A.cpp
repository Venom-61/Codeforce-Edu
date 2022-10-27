#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, res = 0; 
    ll x = 0; 
    for(int r = 0; r < n; r++) {
        x += a[r];
        while(x > s) {
            x -= a[l++];
        }
        res = max(res, r - l + 1);
        // cout << l << " " << r << " " << x << endl;
    }
    cout << res << "\n";

    return 0;
} 
