class Solution {
public:
    int getNum(int num, int remaining){
        if(num - 6 + 1 >= remaining){
            return 6;
        }else if(num - 5 + 1>= remaining){
            return 5;
        }else if(num - 4  + 1>= remaining){
            return 4;
        }else if(num - 3 + 1 >= remaining){
            return 3;
        }else if(num - 2 + 1 >= remaining){
            return 2;
        }else if(num - 1 + 1 >= remaining){
            return 1;
        }

        return -1;
    }

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = rolls.size() + n;

        int sumOfRolls = 0;

        for(auto it : rolls) sumOfRolls += it;

        int totalSum = mean* total;

        int missingSum = totalSum - sumOfRolls;

        vector<int> ans(n);

        double check = (double)missingSum/n;

        if(check > 6.0) return {};

        for(int i = 0;i < n;i++){
            int num = getNum(missingSum, n-i);

            if(num == -1) return {};

            missingSum -= num;

            ans[i] = (num);

        }

        return ans;
    }
};