#include<bits/stdc++.h>
using namespace std;

#define int long long

// G. Student Councils

int k, n;
vector<int> arr;

bool good(int x) {
	int sum = 0;
	for(int i=0; i<n; i++) 
		sum += min(x, arr[i]);
 
	return sum >= x * k;
}

int32_t main() {
	cin >> k >> n;

	arr.resize(n);
	int sum = 0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	// Binary search the number of councils
	int l = 0;				// good;
	int r = (sum / k + 5);	// bad;
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
