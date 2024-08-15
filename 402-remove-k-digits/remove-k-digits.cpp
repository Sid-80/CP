class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s1;

        for(auto it : num){
            while(!s1.empty() && k > 0 && s1.top() > it){
                s1.pop();
                k--;
            }
            s1.push(it);
        }

        while(k > 0 && !s1.empty()){
            s1.pop();
            k--;
        }

        string ans = "";

        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }

        reverse(ans.begin(),ans.end());

        while(ans[0] == '0'){
            ans = ans.substr(1);
        }

        return ans == "" ? "0" : ans;
    }
};