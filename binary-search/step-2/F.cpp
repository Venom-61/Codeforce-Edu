#include<bits/stdc++.h>
using namespace std;

// F. String Game

string s1, s2;
int n, m;
vector<int> arr;

bool good(int x) {
	string str = s1; 
	for(int i=0; i<x; i++) 
		str[arr[i] - 1] = '*';

	string ss = "";
	for(int i=0; i<n; i++) 
		if(str[i] != '*')
			ss += str[i];
	int sz = ss.size(); 
	
	int i=0; // sz, ss
	int j=0; // m, s2
	while(i < sz and j < m) {
		if(ss[i] == s2[j]) {
			i++; j++;
		} else {
			i++;
		}
	}

	return j >= m;
}

int32_t main() {
	cin >> s1 >> s2;

	n = s1.size();
	m = s2.size();

	arr.resize(n);
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	int l = 0; // good
	int r = n; // bad
	while(r > l + 1) {
		int mid = (l + r) / 2;
		if(good(mid)) 
			l = mid;
		else 
			r = mid;
	}
	cout << l << endl;
}

