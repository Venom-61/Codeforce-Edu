#include<bits/stdc++.h>
using namespace std;

#define int long long

// B. Splitting an Array

int n, k;
vector<int> arr;

bool good(int x) {
	int cnt = 0, curr = 0;
	for(int i=0; i<n; i++) {
		if(arr[i] > x) 
			return false;

		if(curr + arr[i] <= x) {
			curr += arr[i];
		} else {
			cnt++;
			curr = arr[i];
		}
	}
	cnt++;

	return cnt <= k;
}

int32_t main() {
	cin >> n >> k;
	arr.resize(n);

	int sum = 0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
		
	// Binary search the sum
	int l = 0;		// bad
	int r = sum;	// good

	while(r > l + 1) {
		int mid = (r + l) / 2;
		if(good(mid)) 
			r = mid;
		else 
			l = mid;
	}
	cout << r << endl;

	return 0;
}
