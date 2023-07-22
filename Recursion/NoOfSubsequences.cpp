// Print number of Subsequences whose sum is K;

#include<bits/stdc++.h>
using namespace std;

int SubSeq(int ind, int arr[], int n, int sum, int initialSum){
    if(ind == n){
        if(initialSum == sum){
            return 1;
        }
        return 0;
    }
    // Take or not particular subsequence to get next subsequence
    initialSum += arr[ind];
    int l = SubSeq(ind+1, arr, n, sum, initialSum);

    initialSum -= arr[ind];
    int r = SubSeq(ind+1, arr, n, sum, initialSum);

    return l + r;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    cout<<SubSeq(0, arr, n, sum, 0);
    return 0;
}