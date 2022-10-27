#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define nline "\n"
 
// Bit strings
 
const int mod = 1e9 + 7;
 
ll binpow(ll a, ll b) {
	if(b == 0) 
		return 1;
	ll res = binpow(a , b/2);
	if(b % 2)
		return (res * res * a) % mod;
	else 
		return (res * res) % mod;
}
 
int main() {
	int n;
	cin >> n;
	cout << binpow(2, n);
}