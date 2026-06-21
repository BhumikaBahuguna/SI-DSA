#include<bits/stdc++.h>
using namespace std;
void updateValue(int arr[], int index, int newVal){
    arr[index] = newVal;
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
    cout << "Original Array: ";
    printArray(arr, n);
    int q;
    cin >> q;
    while(q--){
        int index, newVal;
        cin >> index >> newVal;
        if(index < 0 || index >= n){
            cout << "Invalid Index" << endl;
            continue;
        }
        updateValue(arr, index, newVal);
        cout << "Updated Array: ";
        printArray(arr, n);
    }
    return 0;
}