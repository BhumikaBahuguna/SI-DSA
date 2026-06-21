#include <bits/stdc++.h>
using namespace std;
void buildtree(const vector<int>& arr, vector<int>& segtree, int i, int sl, int sr) {
    if(sl == sr) {
        segtree[i] = arr[sl];
        return;
    }
    int mid = sl + (sr - sl) / 2;
    buildtree(arr, segtree, 2 * i + 1, sl, mid);
    buildtree(arr, segtree, 2 * i + 2, mid + 1, sr);
    segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
}
void update(vector<int>& arr, vector<int>& segtree, int i, int val, int si, int sl, int sr) {
    if(sl == sr) {
        segtree[si] = val;
        arr[i] = val; 
        return;
    }
    int mid = sl + (sr - sl) / 2;
    if(i > mid) update(arr, segtree, i, val, 2 * si + 2, mid + 1, sr);
    else update(arr, segtree, i, val, 2 * si + 1, sl, mid);
    segtree[si] = segtree[2 * si + 1] + segtree[2 * si + 2];
}
int rangesum(const vector<int>& segtree, int si, int sl, int sr, int ql, int qr) {
    if(ql <= sl && qr >= sr) return segtree[si];
    if(sr < ql || sl > qr) return 0;
    int mid = sl + (sr - sl) / 2;
    return rangesum(segtree, 2 * si + 1, sl, mid, ql, qr) + rangesum(segtree, 2 * si + 2, mid + 1, sr, ql, qr);
}
int main() {    
    int n;
    if(!(cin >> n) || n <= 0) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> segtree(4 * n, 0);
    buildtree(arr, segtree, 0, 0, n - 1);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            if(l < 0 || r < 0 || l >= n || r >= n || l > r) cout << "Invalid Range\n";
            else cout << rangesum(segtree, 0, 0, n - 1, l, r) << "\n";
        } else if(t == 2) {
            int index, newVal;
            cin >> index >> newVal;
            if(index < 0 || index >= n) cout << "Invalid Index\n";
            else {
                update(arr, segtree, index, newVal, 0, 0, n - 1);
                cout << "Updated Successfully\n";
            }
        } else cout << "Invalid Query Type\n";
    }
    return 0;
}