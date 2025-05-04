class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        int sn = s.size(), ans = 0;

        for(int i = 0;i < sn;i++){
            int i1 = s[i] - '0';
            for(int j = i+1;j < sn;j++){
                int i2 = s[j]-'0';
                ans = max(ans, i2 * i1);
            }
        }


        return ans;
    }
};