#include<bits/stdc++.h>
using namespace std;

// D. Fast search

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	// 1 3 4 10 10

	int k;
	cin >> k;
	for(int i=0; i<k; i++) {
		int a, b;
		cin >> a >> b;

		// for a
		int l1 = -1; // a[l1] < a
		int r1 = n; // a[r1] >= a
		while(r1 > l1 + 1) {
			int mid = (l1 + r1) / 2;
			if(arr[mid] < a) 
				l1 = mid;
			else 
				r1 = mid;
		} // ans is in r1


		// for b
		int l2 = -1; // a[l2] <= b
		int r2 = n; // a[l2] > b
		while(r2 > l2 + 1) {
			int mid = (l2 + r2) / 2;
			if(arr[mid] <= b) 
				l2 = mid;
			else 
				r2 = mid;
		} // ans is in l2

		cout << abs(l2 - r1 + 1) << " ";
	}
	cout << endl;
}

