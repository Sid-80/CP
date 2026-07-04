class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int tar = target - '0';

        int start = 0, end = letters.size() - 1;

        char ans = '^';

        while(start <= end){
            int mid = start + (end - start) / 2;
            int t = letters[mid] - '0';

            if(t > tar){
                ans = letters[mid];
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }

        

    
        return ans == '^' ? letters[0] : ans;
    }
};