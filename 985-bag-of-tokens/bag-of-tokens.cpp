class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0, ans = 0;
        int i = 0, j = tokens.size()-1;

        while(i <= j){
            if(tokens[i] <= power){
                score += 1;
                power -= tokens[i];
                ans = max(ans,score);
                i++;
            }else if(score >= 1){
                score -= 1;
                power += tokens[j];
                j--;
            } else break;
        }

        return ans;
    }
};