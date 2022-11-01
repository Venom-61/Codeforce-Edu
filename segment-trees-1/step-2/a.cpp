#include<bits/stdc++.h>
using namespace std;

// Segment with the Maximum Sum  

struct item {
    long long seg, pref, suf, sum;
};

struct segTree {
    int size;
    vector<item> values;

    item NEUTRAL = {0, 0, 0, 0};

    // Merge two item into one 

    item merge(item a, item b) {
        return {
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    item single(int v) {
        if(v > 0) 
            return {v, v, v, v};
        else 
            return {0, 0, 0, v};
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
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    segTree st;
    st.init(n);
    st.build(a);

    cout << st.calc(0, n).seg << "\n";
    while(q--) {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.calc(0, n).seg << "\n";
    }

    return 0;
}

