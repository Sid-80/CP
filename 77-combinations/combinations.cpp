class Solution {

    void getAns(vector<vector<int>> & ans, vector<int> & combination, int n, int k, int index){
            if(combination.size()==k){
                ans.push_back(combination);
                return;
            }

        for(int i = index; i < n + 1;i++){
            combination.push_back(i);
            getAns(ans,combination,n,k,i+1);
            combination.pop_back();
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combination;

        getAns(ans,combination,n,k,1);
        return ans;
    }
};