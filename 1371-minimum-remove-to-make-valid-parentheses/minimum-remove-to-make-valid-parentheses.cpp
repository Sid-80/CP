class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int tmp = 0;
        string ans = "";
        for(auto i : s){
            if(i != '(' && i != ')'){
                ans += i;
                continue;
            }
            if(i == '('){
                ans+=i;
                tmp++;
            }else{
                if(tmp <= 0){
                    continue;
                }
                ans+=i;
                tmp--;
            }
        }

        if(tmp <= 0) return ans;

        string ans2="";
        int tmpLen = ans.size() - 1;

        for(int i = tmpLen; i >= 0;i--){
            if(tmp > 0 && ans[i] == '(' ) {
                tmp--;
            }else{
                ans2+=ans[i];
            }
        }

        reverse(ans2.begin(),ans2.end());

        return ans2;
    }



};