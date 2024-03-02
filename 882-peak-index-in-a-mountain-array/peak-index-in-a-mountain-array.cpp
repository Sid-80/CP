class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() - 1;

        if(n == 1) return 0;

        if(arr[0] > arr[1]) return 0;


        if(arr[n-1] > arr[n-2]) return n-1;

        int h = n - 1, l = 1;


        while(l <= h){

            int m = (h + l)/2;
            // cout<<m<<endl;

            if(arr[m] > arr[m-1] && arr[m+1] < arr[m]) return m;

            if(arr[m] > arr[m-1]){
                l = m + 1;
            }else{
                h = m-1;
            }

        }

        return -1;
    }
};