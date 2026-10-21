class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int isSorted = 1;
        int mini = s[0], maxi = s[0];

        for(int i = 1;i < n;i++){
            if(s[i] < s[i - 1]) isSorted = 0;
            if(s[i] < mini) mini = s[i]; 
            if(s[i] > maxi) maxi = s[i]; 
        }

        if(isSorted) return 0;
        if(n == 2) return -1;
        if(mini == s[0] || maxi == s[n-1]) return 1;

        for(int i = 1;i < n-1;i++){
            if(mini == s[i] || maxi == s[i]) return 2;
        }

        return 3;
    }
};