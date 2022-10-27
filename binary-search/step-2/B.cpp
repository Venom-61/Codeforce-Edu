#include<bits/stdc++.h>
using namespace std;

// B. Ropes

int n, k;
vector<int> a;

bool good(double x) {
	int s = 0;
	for(int i=0; i<n; i++) {
		s += a[i] / x;
	}
	return s >= k;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++) cin >> a[i];

	double l = 0;		// good
	double r = 1e8;		// bad

	for(int i=0; i<100; i++) {
		double mid = (l + r) / 2;
		if(good(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << setprecision(20) << l << endl;

	return 0;
}
