class Solution {

    bool check(vector<int> w, int days, int cap){
        int sum=0;
        int ans=1;
        for(auto x: w){
            sum+=x;
            if(x>cap){
                return false;
            }
            if(sum>cap){
                ans++;
                sum=x;
            }
        }
        if(ans<=days){
            return true;
        }
        return false;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, h = 0;

        for(auto it: weights){
            h += it;
        }

        while(l <= h){
            int m = (l + h)/2;

            if(check(weights,days,m)){
                h = m - 1;
            }else{
                l = m + 1;
            }

        }

        return l;
    }
};