class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target) return {i+1,j+1};
            if(numbers[i]+numbers[j]<target){
                i++;
                while(i<j && numbers[i-1]==numbers[i]) i++;
            }
            else{
                j--;
                while(i<j && numbers[j+1]==numbers[j]) j--;
            }
        }
        return {-1,-1};
    }
};