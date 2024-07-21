class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();

        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<n;i++){
            int a=abs(arr[i]-x);
            maxHeap.push({a,arr[i]});
            if(maxHeap.size()>k) maxHeap.pop();
        }

        while(maxHeap.size()>0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};