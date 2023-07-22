// Print any one Subsequences whose sum is K;

#include<bits/stdc++.h>
using namespace std;

bool SubSeq(int ind, int arr[], int n, vector<int> &ans, int sum, int initialSum){
    if(ind == n){
        if(initialSum == sum){
            for(auto v : ans){
                cout<<v<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    // Take or not particular subsequence to get next subsequence
    ans.push_back(arr[ind]);
    initialSum += arr[ind];
    if(SubSeq(ind+1, arr, n, ans, sum, initialSum) == true) return true;

    initialSum -= arr[ind];
    ans.pop_back();
    if(SubSeq(ind+1, arr, n, ans, sum, initialSum)) return true;

    return false;
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