#include<bits/stdc++.h>
using namespace std;

// E. Equation

double c;

bool func(double x) {
	return (x*x + sqrt(x)) <= c;
}

int32_t main() {
	cin >> c;

	double l = 0;	// good 
	double r = 1e9; // bad;
	for(int i=0; i<100; i++) {
		double mid = (l + r) / 2;
		if(func(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << setprecision(20) << l << endl;
}

