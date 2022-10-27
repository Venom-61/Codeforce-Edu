#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

// repetitions
 
int main() {
	string s;
	cin >> s;
	int count = 0;
	int max = 0;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			count++;
			if (count > max)
				max = count;
		}
		else
			count = 0;
	}
	cout << max + 1;
}