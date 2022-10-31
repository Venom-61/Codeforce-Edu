#include<bits/stdc++.h>
using namespace std;

// Segment tree for the sum

struct segTree {

    int size;
    vector<long long> sums;

    int NEUTRAL = 0;

    // Initialize the Segment Tree

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0LL);
    }

    // Build the Segment Tree from an array
    
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return ;
        }
        
        int m = (lx + rx) / 2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);

        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    // Set the value to index in Segment Tree

    void set(int i,int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return ;
        }
         
        int m = (lx + rx) / 2;
        if(i < m)
            set(i, v, 2*x + 1, lx, m);
        else 
            set(i, v, 2*x + 2, m, rx);

        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // Calculate the sum int Segment Tree

    long long sum(int l, int r, int x, int lx, int rx) {
        if(lx >= r or l >= rx) return NEUTRAL;
        if(lx >= l and rx <= r) return sums[x];
        
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x + 1, lx, m);
        long long s2 = sum(l, r, 2*x + 2, m, rx);
        return s1 + s2; 
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

};

int main() {
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x : a) 
        cin >> x;

    segTree st;
    st.init(n);
    st.build(a);

    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
    }


    return 0;
}

