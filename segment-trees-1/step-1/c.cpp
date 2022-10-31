#include<bits/stdc++.h>
#include <climits>
using namespace std;

// Segment tree for the number of minimum

struct item {
    int m, c;
};

struct segTree {
    int size;
    vector<item> values;

    item NEUTRAL = {INT_MAX, 0};

    // Merge two item into one 
    item merge(item a, item b) {
        if(a.m < b.m) return a;
        if(a.m > b.m) return b;
        return {a.m, a.c + b.c};
    }

    item single(int x) {
        return {x, 1};
    }

    // Initialize the Segment Tree

    void init(int n) {
        size = 1;
        while(size < n) 
            size *= 2;
        values.resize(2*size);
    }

    // Build the Segment Tree from an array
    
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                values[x] = single(a[lx]);
            }
            return ;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        values[x] = merge(values[2*x + 1], values[2*x + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    // Set the value to index in Segment Tree

    void set(int i,int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = single(v);
            return ;
        }
        int m = (lx + rx) / 2;
        if(i < m) set(i, v, 2*x + 1, lx, m);
        else set(i, v, 2*x + 2, m, rx);
        values[x] = merge(values[2*x + 1], values[2*x + 2]);
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // Calculate the sum int Segment Tree

    item calc(int l, int r, int x, int lx, int rx) {
        if(lx >= r or l >= rx) return NEUTRAL;
        if(lx >= l and rx <= r) return values[x];
        
        int m = (lx + rx) / 2;
        item s1 = calc(l, r, 2*x + 1, lx, m);
        item s2 = calc(l, r, 2*x + 2, m, rx);
        return merge(s1, s2); 
    }

    item calc(int l, int r) {
        return calc(l, r, 0, 0, size);
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
            auto ans = st.calc(l, r);
            cout << ans.m << " " << ans.c << "\n";
        }
    }

    return 0;
}

