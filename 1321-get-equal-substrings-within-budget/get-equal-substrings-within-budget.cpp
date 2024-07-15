class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, ans = 0;


        long long cost = 0;

        int n = s.size();

        if(s == t) return n;
        
        for(int end = 0;end < n;end++){
            cost = cost + abs(s[end] - t[end]);

            if(cost <= maxCost) ans = max(ans,end-start+1);

            if(cost >= maxCost){
                cost = cost - abs(s[start] - t[start]);
                
                start++;
            }

        }

        return ans;

    }
};