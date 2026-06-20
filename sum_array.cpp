#include<bits/stdc++.h>
using namespace std;
int findsum(int arr[],int l,int r){
    int sum=0;
    for(int i=l;i<=r;i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(r<l)
            cout << "Invalid range" << endl;
        else 
            cout<<findsum(arr,l,r)<<endl;
    }
    return 0;
}