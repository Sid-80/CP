class Solution {
public:
    string removeOuterParentheses(string s) {
        int tmp = 0;
        string ans = ""; 
        for(auto i : s){            
            if(i == '('){
                if(tmp != 0){
                    ans+= '(';
                }
                    tmp++;
            }else{
                tmp--;
                if(tmp != 0){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};