class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;

        for(auto it : nums){
            if(m.count(it) > 0){
                return true;
            }else{
                m[it] = 1;
            }
        }

        return false;
    }
};