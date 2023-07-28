#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;

        while(j < nums.size()){
            
            
            if(sum == target){
                cout<<sum<<endl;
                ans = min(ans,j-i+1);
                sum -= nums[i];
                i++;
                // j++;
            }else if(sum < target){
                sum += nums[j];
                j++;
            }else if(sum > target){
                while(sum > target){
                    sum -= nums[i];
                    i++;
                }
                // j++;
            }
            // if(sum == target){
            //     cout<<i<<" "<<j<<endl;
            //     if(ans > j-i+1)
            //         ans = j-i+1;
            //     sum = sum - nums[i];
            //     i++;
            // }else if(sum > target){
            //     while(sum > target){
            //         sum -= nums[i];
            //         i++;
            //     }
            // }else if(sum < target){
            //     sum = sum + nums[j];
            //     j++;
            // }
        }

        if(ans == INT_MAX) return 0;

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,1,4};
    Solution s1;
    cout<<s1.minSubArrayLen(4,nums);


    return 0;
}
