/*
    [1,1,2,2,3,3,4,5,5,6,6]
    0,1,2,3,4,5,6,7,8,9,10

    if mid is on 4 and low =0 & high = 10 then
    1. at low if(even,odd index (mid = odd and mid-1 = even and mid = mid-1) having same value then it is on right half)
    2. for high if(odd,even index (next to mid) having same value then it is on left half)

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        else if(nums[n-1] != nums[n-2]) return nums[n-1];

        int h = n-2, l = 1;

        while(l <= h){

            int m = (l + h)/2;
            
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1]) return nums[m];

            if((m % 2 != 0 && nums[m-1] == nums[m]) || (m % 2 == 0 && nums[m+1] == nums[m]) ){//element is on right half
                l= m + 1;
            }else{ //left half
                h = m - 1; 
            }

        }

        return -1;
    }
};