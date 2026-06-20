#include<bits/stdc++.h>
using namespace std;
void buildBlocks(int arr[], vector<int>& block, int n, int blockSize)
{
    for(int i=0; i<n; i++)
    {
        block[i / blockSize] += arr[i];
    }
}
bool isValidRange(int l, int r, int n)
{
    return !(l < 0 || r < 0 || l >= n || r >= n || l > r);
}
void update(int arr[], vector<int>& block, int index, int newVal, int blockSize)
{
    int blockNum = index / blockSize;

    block[blockNum] += (newVal - arr[index]);

    arr[index] = newVal;
}
int rangeSum(int arr[], vector<int>& block, int l, int r, int blockSize)
{
    int sum = 0;

    while(l <= r && l % blockSize != 0)
    {
        sum += arr[l];
        l++;
    }
    while(l + blockSize - 1 <= r)
    {
        sum += block[l / blockSize];
        l += blockSize;
    }
    while(l <= r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int blockSize = sqrt(n);
    if(blockSize == 0)
        blockSize = 1;
    int numBlocks = (n + blockSize - 1) / blockSize;
    vector<int> block(numBlocks, 0);
    buildBlocks(arr, block, n, blockSize);
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        switch(t)
        {
            case 1:
            {
                int l, r;
                cin >> l >> r;
                if(!isValidRange(l, r, n))
                {
                    cout << "Invalid Range" << endl;
                }
                else
                {
                    cout << rangeSum(arr, block, l, r, blockSize) << endl;
                }
                break;
            }
            case 2:
            {
                int index, val;
                cin >> index >> val;
                if(index < 0 || index >= n)
                {
                    cout << "Invalid Index" << endl;
                }
                else
                {
                    update(arr, block, index, val, blockSize);
                    cout << "Updated Successfully" << endl;
                }
                break;
            }
            default:
            {
                cout << "Invalid Query Type" << endl;
            }
        }
    }
    return 0;
}