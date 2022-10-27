#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0, ans = 0; 
    for(int j=0; j<m; ) {
        int cnt = 0, cc = 1;
        while(a[i] < b[j] and i < n) 
            i++;
        while(a[i] == b[j] and i < n) 
            cnt++, i++;

        int k = j+1;
        while(b[k] == b[j] and k < m) 
            cc++, k++;

        ans += cc * cnt;
        j = k;
    }
    cout << ans << endl;

    return 0;
}
