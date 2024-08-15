class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;

        for(auto it : bills){
            if(it == 10){
                if(m.find(5) != m.end() && m[5] > 0){
                    m[5] -= 1;
                } else return false;
            }
            if(it == 20){
                if(m.find(10) != m.end() && m.find(5) != m.end() && m[5] > 0 && m[10] > 0){
                    m[10] -= 1;
                    m[5] -= 1;
                } else if(m.find(5) != m.end() && m[5] >= 3){
                    m[5] -= 3;
                } else return false;
            }
            m[it] += 1;
        }
        
        return true;
    }
};