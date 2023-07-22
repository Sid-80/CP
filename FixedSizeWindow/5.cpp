#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int totalNums = nums.size();
        int sum = 0;
        int i = 0, j = 0, m = k;
        vector<int> ans;
        while(j < k){
            ans.push_back(-1);
            sum += nums[j];
            j++;
        }
        while(j < totalNums){
            if((j - m) < k){
                sum+=nums[j];
                j++;
            }else if((j-m) == k){
                sum+=nums[j];
                cout<<sum<<endl;
                ans.push_back(sum/(2*k+1));
                sum -= nums[i];
                i++;
                m++;
                j++;
            }
        }
        while(m < totalNums){
            ans.push_back(-1);
            m++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    vector<int> v1 = {3,3};
    int k = 3;
    v1 = s1.getAverages(v1,3);
    for(auto v : v1)
    {
        cout << v <<" ";
    }
    
    return 0;
}