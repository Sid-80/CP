class Solution {
public:
    int maxDepth(string s) {
        int n = 0;
        
        int ans = 0, tmp = 0;

        for(auto i : s){
            if(i == '('){
                ans++;
                tmp = max(tmp,ans);
            }else if(i == ')' ){
                ans--;
            }
        }

        return tmp;
    }
};