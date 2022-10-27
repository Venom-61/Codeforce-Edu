#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define nline "\n"

// Two sets
 
void solve() {
	ll n;
	cin >> n;
	ll tot = n*(n+1)/2;
	if(tot%2) {
		cout << "NO" << nline;
		return ;
	}
 
	ll sum=0;
	tot = tot/2;
 
	vector<int> a1, a2;
	for(ll i=n; i>0; i--) {
		if(sum+i <= tot) {
			sum += i;
			a1.push_back(i);
		} else {
			a2.push_back(i);
		}
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
 
	cout << "YES" << nline;
	cout << a1.size() << nline;
	for(auto x : a1) cout << x << " " ;
	cout << nline;
 
	cout << a2.size() << nline;
	for(auto x : a2) cout << x << " " ;
	cout << nline;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	solve();
	return 0;
}