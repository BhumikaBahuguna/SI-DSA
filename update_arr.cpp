#include<bits/stdc++.h>
using namespace std;

void buildPrefixSum(int arr[], int pre[], int n){
    pre[0] = arr[0];

    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + arr[i];
    }
}

void updateValue(int arr[], int pre[], int n, int index, int newVal){
    int diff = newVal - arr[index];

    arr[index] = newVal;

    for(int i=index; i<n; i++){
        pre[i] += diff;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int pre[n];
    buildPrefixSum(arr, pre, n);

    cout << "Prefix Sum Array: ";
    printArray(pre, n);

    int q;
    cin >> q;

    while(q--){
        int index, newVal;
        cin >> index >> newVal;

        updateValue(arr, pre, n, index, newVal);

        cout << "Updated Array: ";
        printArray(arr, n);

        cout << "Updated Prefix Sum: ";
        printArray(pre, n);
    }

    return 0;
}