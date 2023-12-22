class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int n = s.size();
        for(int i = 0;i < n - 1;i++){
            int initial = 0;
            int j = i+1,ans = 0;
            
            while(initial < j){
                if(s[initial] == '0'){
                    ans++;
                }
                initial++;
            }
            while(initial < n){
                if(s[initial] == '1'){
                    ans++;
                }
                initial++;
            }

            score = max(score,ans);
        }

        return score;
    }
};