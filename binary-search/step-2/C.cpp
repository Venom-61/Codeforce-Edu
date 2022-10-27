#include<bits/stdc++.h>
using namespace std;

// C. Very Easy Task

int n, x, y;

bool good(int t) {
	return (t/x + (t-x)/y) >= n;
}

int main() {
	ios::sync_with_stdio(false);	

	cin >> n >> x >> y;
	if(x > y) swap(x, y);

	int l = 0; // is bad
	int r = 1; // is good
	while(!good(r)) r *= 2;

	while(r > l+1) {
		int mid = (l + r) / 2;
		if(good(mid)) 
			r = mid;
		else 
			l = mid;
	}
	cout << r << endl;

	return 0;
}
