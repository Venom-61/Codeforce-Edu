#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    vector<int> c(n + m);

    int i = 0, j = 0, k = 0;
    while(i < n or j < m) {
        if(j == m or i < n and a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    for(auto i : c) {
        cout << i << " " ;
    }
    cout << endl;
    
    return 0;
}
