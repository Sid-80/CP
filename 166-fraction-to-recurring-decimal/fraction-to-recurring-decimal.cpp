class Solution {
public:
    string fractionToDecimal(int x, int y) {
        string ans = "";
        
        if(x == 0) return "0";

        if((x < 0) ^ (y < 0)) ans.push_back('-');


        long num = labs((long) x);
        long den = labs((long) y);

        ans += to_string(num / den);

        long long rem = num % den;

        if( rem== 0) return ans;

        unordered_map<long, long> mp;
 
        ans+='.';


            
        while(rem != 0){
            if(mp.count(rem)){
                ans.insert(mp[rem], "(");
                ans.push_back(')');
                return ans;
            }

            mp[rem] = ans.size();
            rem*= 10;
            ans += to_string(rem/den);
            rem %= den;
        }

        return ans;
    }
};