#include <bits/stdc++.h>
using namespace std;
vector<int> buildsqrtarray(const vector<int>& arr, int n, int block_size) {
    int num_blocks = (n + block_size - 1) / block_size;
    vector<int> sqrtdecomposed(num_blocks, 0);
    for(int i = 0; i < n; i++) {
        sqrtdecomposed[i / block_size] += arr[i];
    }
    return sqrtdecomposed;
}
void update(vector<int>& arr, vector<int>& sqrtdecomposed, int i, int newval, int block_size) {
    int blocknumber = i / block_size;
    int diff = newval - arr[i];
    arr[i] = newval;
    sqrtdecomposed[blocknumber] += diff;
}
int rangesum(const vector<int>& arr, const vector<int>& sqrtdecomposed, int l, int r, int block_size) {
    int sb = l / block_size;
    int eb = r / block_size;
    int sum = 0;
    if (sb != eb) {
        for(int i = sb + 1; i < eb; i++) sum += sqrtdecomposed[i];
        int i = l;
        while(i / block_size == sb) { sum += arr[i]; i++; }
        int k = r;
        while(k / block_size == eb) { sum += arr[k]; k--; }
    } else {
        for(int i = l; i <= r; i++) sum += arr[i];
    }
    return sum;
}
int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int block_size = sqrt(n) + 1; 
    vector<int> blocks = buildsqrtarray(arr, n, block_size);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            cin >> l >> r;
            if(l < 0 || r < 0 || l >= n || r >= n || l > r) cout << "Invalid Range\n";
            else cout << rangesum(arr, blocks, l, r, block_size) << "\n";
        } else if(t == 2) {
            int index, newVal;
            cin >> index >> newVal;
            if(index < 0 || index >= n) cout << "Invalid Index\n";
            else {
                update(arr, blocks, index, newVal, block_size);
                cout << "Updated Successfully\n";
            }
        } else cout << "Invalid Query Type\n";
    }
    return 0;
}
