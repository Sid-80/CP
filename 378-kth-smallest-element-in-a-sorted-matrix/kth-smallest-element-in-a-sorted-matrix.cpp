class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();

        priority_queue<int> maxHeap;
        int cnt = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(cnt <= k-1){
                    maxHeap.push(matrix[i][j]);
                    cnt++;
                }else{
                    if(maxHeap.top() > matrix[i][j]){
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }
        }

        return maxHeap.top();

    }
};