class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int left= 0;
        for (; left+1 < n && arr[left] <= arr[left+1]; left++); 
        
        if (left== n-1) return 0;

        vector<int> stack={n-1};
        for (int r= n-2; r>left; r--) {
            if (arr[r] <= arr[r+1])
                stack.push_back(r);
            else break;
        }

        int remove= min(n-left-1, stack.back());

        for (int i = 0; i <=left; i++) {
            while (!stack.empty() && arr[i]>arr[stack.back()])
                stack.pop_back();
    
            if (!stack.empty()) 
                remove = min(remove, stack.back()-i-1);
        }

        return remove;

    }
};