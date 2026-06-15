class Solution {
public:
    pair<int,int> digitFun(int n){
        int sum = 0;
        int ss = 0;
        while(n != 0){
            sum += (n % 10);
            ss += (n % 10) * (n % 10);
            n = n / 10;
        }
        return {sum, ss};
    }

    bool checkGoodInteger(int n) {
        pair<int,int> ans = digitFun(n);
        return (ans.second - ans.first >= 50);
    }
};