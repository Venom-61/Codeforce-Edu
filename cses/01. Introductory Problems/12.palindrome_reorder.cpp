#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
#define nline "\n"
 
void solve() {
	string s;
	cin >> s;
	map<char, int> mp;
	for(int i=0; i<s.size(); i++) {
		mp[s[i]]++;	
	}
	
	bool ok = true;
	string str="", odd="";
	
	for(auto m : mp) {
		if(m.second % 2 == 0)
			for(int i=0; i<m.second/2; i++) {
				str += m.first;
		} else {
			if(ok) {
				ok = false;
				for(int i=0; i<m.second; i++) {
					odd += m.first;
				}
			} else {
				cout << "NO SOLUTION" << endl;
				return ;
			}
		}
	}
	
	string rev = str;
	reverse(rev.begin(), rev.end());
	string ans = str + odd + rev;
	cout << ans << endl;
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	solve();
	return 0;
}