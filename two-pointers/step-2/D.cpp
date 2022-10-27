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

    int l = 0; 
    ll res = 0; 
    ll x = 0; 
    for(int r = 0; r < n; r++) {
        x += a[r];
        while(x >= s) {
            x -= a[l++];
        } 
        // ? l .. r is largest bad
        // this means r - l + 1 segments are bad 
        // ? 0 .. l - 1 is smallest good
        // then l segments are good
            
        res +=  l;
    }
    cout << res << "\n";

    return 0;
} 
