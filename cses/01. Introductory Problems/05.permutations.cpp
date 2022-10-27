#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define nline "\n"
 
// Permutations
 
void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << nline;
	} else if(n == 2 or n == 3) {
		cout << "NO SOLUTION" << nline;
	} else {
		for(int i=n; i>0; i--) if(i%2 ==1) cout << i << " ";
		for(int i=n; i>0; i--) if(i%2 ==0) cout << i << " ";
		cout << nline;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
 
	return 0;
}