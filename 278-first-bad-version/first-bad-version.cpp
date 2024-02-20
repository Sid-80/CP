// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long high = n, low = 1;

        long ans = n;
        while(low <= high){
            long mid = (low + high)/2;

            bool res = isBadVersion(mid);

            if(res == true){
                ans = min(ans,mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            
        }

        return ans;
    }
};