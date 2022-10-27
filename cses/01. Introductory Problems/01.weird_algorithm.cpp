#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

// weird algorithm
 
int main() {
	ll n;
	cin >> n;
	while (n > 1) {
		cout << n << ' ';
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
	}
	cout << 1;
}