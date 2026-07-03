class Solution {
public:
    bool canEat(int h, vector<int> b, int k){
        long long int sum = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] % k == 0) {
                sum += (b[i] / k);
            } else {
                sum += (b[i] / k) + 1;
            }
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int start = 1;

        int end = start;

        for(auto it : piles){
            end = max(end, it);
        }
        
        int u = 1, ans = -1;

        while(start <= end && u == 1){
            int mid = (start + end) / 2;
            if(canEat(h, piles, mid)){
                if(mid == 1){
                    ans = 1;
                    u= 0;
                }else if(canEat(h, piles, mid - 1) == false){
                    ans = mid;
                    u = 0;
                } else {
                    end = mid - 1;
                }
            } else {
                start = mid + 1;
            }
        }

        return ans;

    }
};