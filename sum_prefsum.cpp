#include<bits/stdc++.h>
using namespace std;
int prefsum(int pre[], int l, int r){
    if(l == 0)
        return pre[r];
    else
        return pre[r] - pre[l-1];
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int pre[n];
    pre[0] = arr[0];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l < 0 || r < 0 || l >= n || r >= n || l > r)
            cout << "Invalid range" << endl;
        else
            cout << prefsum(pre, l, r) << endl;
    }
    return 0;
}