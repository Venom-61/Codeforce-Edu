#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define nline "\n"
 
// Two knights
 
void solve() {
	int n; cin >> n;
	for(ll i=1; i<=n; i++) {
		ll a1 = i*i;
		ll a2 = a1*(a1-1)/2;
		if(i>2)
			a2 -= 4*(i-1)*(i-2);
		cout << a2 << nline;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}