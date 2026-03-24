#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct SegTree {
    int n;
    vector<long long> st;

    SegTree(int n_) : n(n_), st(4*n_, LLONG_MIN) {}

    void build(int p, int l, int r, const vector<long long>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, arr);
        build(p<<1|1, m+1, r, arr);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }

    long long query(int p, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return LLONG_MIN;
        if (ql <= l && r <= qr) return st[p];
        int m = (l + r) >> 1;
        return max(query(p<<1, l, m, ql, qr), query(p<<1|1, m+1, r, ql, qr));
    }

    void update(int p, int l, int r, int idx, long long val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) update(p<<1, l, m, idx, val);
        else update(p<<1|1, m+1, r, idx, val);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, Q;
    if (!(cin >> N >> K >> Q)) return 0;
    vector<long long> arr(N+1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    SegTree seg(N);
    seg.build(1, 1, N, arr);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            long long val;
            cin >> pos >> val;
            if (pos >= 1 && pos <= N) {
                seg.update(1, 1, N, pos, val);
            }
        } else if (type == 2) {
            int i;
            cin >> i;
            int L = i - K + 1;
            if (L < 1) L = 1;
            if (i < 1) {
                cout << "-inf"; // invalid, but spec probably ensures valid i
            } else if (L > i || i > N) {
                cout << "-inf"; // invalid query
            } else {
                long long ans = seg.query(1, 1, N, L, i);
                cout << ans;
            }
            if (Q) cout << '\n';
        }
    }

    return 0;
}
