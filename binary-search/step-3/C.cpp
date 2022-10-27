#include<bits/stdc++.h>
using namespace std;

#define int long long

// C. Cows in Stalls

int n, c;
vector<int> arr;

bool good(int x) {
	int cows = 0; 
	int last = arr[0];
	cows++;
	for(int i=1; i<n; i++) {
		if(arr[i] - last >= x) {
			cows++;
			if (cows == c) return true;
			last = arr[i];
		}
	}
	return false;
}

int32_t main() {
	cin >> n >> c;
	arr.resize(n);
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	// Binary Search the distance
	int l = 0;		// bad
	int r = 1e16;	// good

	while(r > l + 1) {
		int mid = (l + r) / 2;
		if(good(mid)) 
			l = mid; 
		else 
			r = mid;
	}
	cout << l << endl;

	return 0;
}
