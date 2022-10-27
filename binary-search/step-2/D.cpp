#include<bits/stdc++.h>
using namespace std;

#define int long long

// D. Children Holiday

struct asst {
	int t, z, y;
};

int m, n;
vector<asst> a;

int countMaxBalloons(int t, int z, int y, int maxTime) {
	int batchTime = z * t + y;
	int batches = maxTime / batchTime;
	int remTime = maxTime % batchTime;
	int totalBalloons = batches * z;
	if(remTime != 0) {
		if(remTime / t >= z) 
			totalBalloons += z;
		else 
			totalBalloons += remTime / t;
	}
	return totalBalloons;
}

bool isBalloonsPossible(int t, int z, int y, int time, int balloons) {
	int batchTime = z * t + y;
	int batches = balloons / z;
	int ok = (balloons % z == 0) ? 1 : 0;
	int currTime = 0;

	if(ok) {
		batches -= 1;
		currTime = batches * batchTime + z * t;
	} else {
		currTime = batches * batchTime + (balloons % z) * t;
	}

	return currTime <= time;
}

bool isPossible(int time) {
	int totalBalloons = 0;
	
	for(int i=0; i<n; i++) {
		int t = a[i].t;
		int z = a[i].z;
		int y = a[i].y;

		// binary search the balloons
		int l = 0;		// good
		int r = 1e9;	//  bad

		while(r > l+1) {
			int balloons = (l+r) / 2;
			if(isBalloonsPossible(t, z, y, time, balloons))
				l = balloons;
			else 
				r = balloons;
		}
		totalBalloons += l;
	}
	return totalBalloons >= m;
}

int32_t main() {
	cin >> m >> n;
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> a[i].t >> a[i].z >> a[i].y;
	}

	// Binary Search the time required to fill m balloons
	int l = -1;		// bad
	int r = 1e9;	// good
			
	while(r > l+1) {
		int time = (l + r) / 2;
		if(isPossible(time)) 
			r = time;
		else 
			l = time;
	}
	cout << r << endl;

	// for indivisual assistants
	vector<int> count(n);
	for(int i=0; i<n; i++) {
		int t = a[i].t;
		int z = a[i].z;
		int y = a[i].y;
		count[i] = countMaxBalloons(t, z, y, r);
	}

	int totalBalloons = 0;
	for(int i=0; i<n; i++) {
		if(totalBalloons + count[i] <= m) {
			cout << count[i] << " ";
			totalBalloons += count[i];
		} else {
			if(totalBalloons == m) 
				cout << 0 << " ";
			else {
				cout << (m - totalBalloons) << " ";
				totalBalloons = m;
			}
		}
	}
	cout << endl;

	return 0;
}
