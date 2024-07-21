class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,  vector<int>, greater<int>> minHeap;
        int n = nums.size();

        int i = 0;

        for(i = 0;i < k;i++){
            minHeap.push(nums[i]);
        }

        for(i = i;i < n;i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};