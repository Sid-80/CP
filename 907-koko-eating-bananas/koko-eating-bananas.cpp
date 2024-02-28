class Solution {

    long req_time(vector<int>& piles, int i){
        long t = 0;

        for(auto it:piles){
            t += ceil((double)it/ (double)i);
        }

        return t;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        long high = *max_element(piles.begin(),piles.end());

        while(l <= high){
            long m = (l + high)/2;
            
            long time = req_time(piles,m);

            if(time <= h){
                high = m -1;
            }else{
                l = m + 1;
            }
        }

        return l;
    }


};