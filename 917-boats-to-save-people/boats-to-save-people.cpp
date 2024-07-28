class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int start = 0, ans = 0, end = n-1;
        
        sort(people.begin(),people.end());

        while( start <= end){

            if(people[end] + people[start] > limit){
                ans++;
                end--;
            }else{
                ans++;
                end--;
                start++;
            }
        }

        return ans;

    }
};