// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

void subsetAll(int ind, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr){
    ans.push_back(ds);
    for(int i = ind; i < arr.size(); i++){
        if(i != ind && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        subsetAll(i+1, ans, ds, arr);
        ds.pop_back();
    }
}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subsetAll(0, ans, ds, nums);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}