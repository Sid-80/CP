class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int pointer_a = 0, pointer_b = 0;
        vector<vector<int>> result;
        int n1 = A.size();
        int n2 = B.size();
        while (pointer_a < n1 && pointer_b < n2){
            if(B[pointer_b][0] <= A[pointer_a][1] && A[pointer_a][0] <= B[pointer_b][1]){
                int start = max(A[pointer_a][0], B[pointer_b][0]);
                int end = min(A[pointer_a][1], B[pointer_b][1]);
                result.push_back({start, end});
            }
            if(A[pointer_a][1] < B[pointer_b][1]){
                pointer_a++;
            }else{
                pointer_b++;
            }
        }
        return result;
    }
};