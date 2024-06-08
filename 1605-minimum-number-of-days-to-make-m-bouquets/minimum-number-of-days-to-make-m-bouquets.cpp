class Solution {

    bool possible(vector<int> bloomDay, int m, int k, int day){
        int cnt = 0;
        int boque= 0;
        for(int i = 0;i < bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                boque += (cnt/k);
                cnt=0;
            }
        }
        boque += (cnt/k);
        return boque >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        long long temp = m * 1LL * k *1LL;

        if(temp > n) return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0;i < n;i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }


        while(low <= high){
            int mid = (low+high)/2;

            if(possible(bloomDay,m,k,mid)){
                high = mid - 1;
            }else{
                low = mid+1;
            }

        }

        return low;

    }
};