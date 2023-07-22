#include<bits/stdc++.h>
using namespace std;

void SubSeq(int ind, int arr[], int n, vector<int> &ans){
    if(ind == n){
        for(auto v : ans){
            cout<<v<<" ";
        }
        cout<<endl;
        return;
    }
    // Take or not particular subsequence to get next subsequence
    ans.push_back(arr[ind]);
    SubSeq(ind+1, arr, n, ans);

    ans.pop_back();
    SubSeq(ind+1, arr, n, ans);
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,1,2};
    int n = 3;
    vector<int>  ans;
    SubSeq(0, arr, n, ans);
    return 0;
}

// Time Complexity = O(2^n)
// Space Complexity = O(n)