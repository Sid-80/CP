class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);

        if(nums.size() == 1) return num;
        
        int start = 0;

        while(start < nums.size()-1 && nums[start] >= nums[start+1] ){
            start++;
        }

        if(start == nums.size()-1) return stoi(nums);
        
        int maxi = nums[start], maxiIndex = start, end = start;

        while(end < nums.size()){
            if(maxi <= nums[end]){
                maxi = nums[end];
                maxiIndex = end;
            }
            end++;
        }
        

            while(start >= 0 && nums[start] < nums[maxiIndex]){
                start--;
            }
            start+=1;

        // cout<<start<<maxiIndex<<endl;

        swap(nums[start],nums[maxiIndex]);

        return stoi(nums);
    }
};