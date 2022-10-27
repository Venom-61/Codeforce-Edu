#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n;
vector<ll> weights;
 
ll solve(int ind, ll s1, ll s2) {
	if(ind == n) {
		return abs(s1 - s2);
	}
	return min(
		solve(ind+1, s1 + weights[ind], s2), 
		solve(ind+1, s1, s2 + weights[ind])
	);
}
 
int main() {
	cin >> n;
	weights.resize(n);
	for(int i=0; i<n; i++) 
		cin >> weights[i];
 
	cout << solve(0, 0, 0) << endl;
}