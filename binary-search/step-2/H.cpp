#include<bits/stdc++.h>
using namespace std;

#define int long long

// H. Hamburgers

struct Number {
	int b, s, c;
};
struct Price {
	int b, s, c;
};

int B=0, S=0, C=0;
Number n;
Price p;
int rubles;

bool good(int x) {
	int reqBreads = max(0*1LL, x*B - n.b);
	int reqSausage = max(0*1LL, x*S - n.s);
	int reqChees = max(0*1LL, x*C - n.c);

	int totalPrice = reqBreads * p.b + reqSausage * p.s + reqChees * p.c;

	return totalPrice <= rubles;
}

int32_t main() {
	string str;
	cin >> str;
	cin >> n.b >> n.s >> n.c;
	cin >> p.b >> p.s >> p.c;
	cin >> rubles;

	for(auto c : str) {
		if(c == 'B') 
			B++;
		if(c == 'S')
			S++;
		if(c == 'C')
			C++;
	}

	// Binary search the number of hamburgers
	int l = 0;		// good
	int r = 1e14;	// bad
	while(r > l + 1) {
		int ham = (l + r) / 2;
		if(good(ham)) 
			l = ham;
		else 
			r = ham;
	}
	cout << l << endl;

	return 0;
}
