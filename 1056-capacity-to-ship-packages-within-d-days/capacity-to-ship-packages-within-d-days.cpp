// Here we will take low as highest weight in array and high as sum of weights

class Solution {
    bool possible(vector<int>& arr, int shipWeight, int days){
        int sum = 0, temp = 1;

        for(int i = 0; i < arr.size();i++){
            if((sum+arr[i]) > shipWeight){
                temp++;
                sum = 0;
            }
            sum += arr[i];
        }

        return temp <= days;
    }

public:
    int shipWithinDays(vector<int>& arr, int days) {
        int high = 0;
        int low = INT_MIN;

        for(auto it : arr){
            high += it;
            low = max(low,it);
        }

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(arr,mid,days)){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};