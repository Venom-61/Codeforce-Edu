#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"

// Creating Strings

void solve() {
	string s;
	cin >> s;
	vector<string> ans;
	
	// imp to sort other wise next_permutation() will fail
	sort(s.begin(), s.end());	
	
	do {
		ans.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	
	cout << ans.size() << endl;
	for(auto s : ans) {
		cout << s << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	
	return 0;
}