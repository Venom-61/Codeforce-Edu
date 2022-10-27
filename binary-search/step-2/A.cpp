#include<bits/stdc++.h>
using namespace std;

#define int long long

// A. Packing Rectangles

int a, b, n;

bool good(int x) {
	return (x / a) * (x / b) >= n;
}

int32_t main() {
	cin >> a >> b >> n;

	int l = 0;		// func(l) = bad
	int r = 1;	// func(r) = good	
	while(!good(r)) r *= 2;

	while(r > l + 1) {
		int mid = (l + r) / 2;
		if(good(mid))
			r = mid;
		else 
			l = mid;
	}
	cout << r << endl;

	return 0;
}
