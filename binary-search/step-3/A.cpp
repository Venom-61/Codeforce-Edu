#include<bits/stdc++.h>
using namespace std;

// A. Get together

int n;
vector<int> x, v;

bool good(double t){
    double maxStart = -1e20;
    double minEnd = 1e20;
    for (int i=0; i<n; i++) {
		double start = x[i] - t*v[i];
		double end = x[i] + t*v[i];
        maxStart = max(start, maxStart);
        minEnd = min(end, minEnd);
    }
	return maxStart <= minEnd;
}

int32_t main(){
    cin>>n;
    x.resize(n);
    v.resize(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> v[i];

    // Binary Search the time 
    double l = 0;       // bad
    double r = 1;    // good
    while(!good(r)) r *= 2;

    for(int i=0; i<100; i++) {
        double mid = (l + r) / 2;
        if (good(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << setprecision(20) << r <<endl;
    return 0;
}
