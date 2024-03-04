class Solution {

    bool check(vector<int> time, int totalTrips, long long t){
        long long temp = 0;

        for(auto it: time){
            long long cal = t/it;
            temp+=cal;
        }

        return (temp >= totalTrips) ? true : false ;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long h = 1e14, l = 1;

        // if(time.size() == 1) return time[0]*totalTrips;

        while(l <= h){
            long long mid = (l + h)/2;

            if(check(time,totalTrips,mid)){
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
};