// Print Subsequences whose sum is K;

#include<bits/stdc++.h>
using namespace std;

void SubSeq(int ind, int arr[], int n, vector<int> &ans, int sum, int initialSum){
    if(ind == n){
        if(initialSum == sum){
            for(auto v : ans){
                cout<<v<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // Take or not particular subsequence to get next subsequence
    ans.push_back(arr[ind]);
    initialSum += arr[ind];
    SubSeq(ind+1, arr, n, ans, sum, initialSum);

    initialSum -= arr[ind];
    ans.pop_back();
    SubSeq(ind+1, arr, n, ans, sum, initialSum);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    vector<int>  ans;
    SubSeq(0, arr, n, ans, sum, 0);
    return 0;
}