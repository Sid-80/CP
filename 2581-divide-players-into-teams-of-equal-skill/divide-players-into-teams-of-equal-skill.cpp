class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // 1,2,3,3,4,5

        int n = skill.size();
        int sum = accumulate(skill.begin(), skill.end(), 0);
        if(sum % (n/2) != 0) return -1;

        int perteam = sum / (n/2);

        sort(skill.begin(), skill.end());

        int start = 0, end = n-1;

        long long ans = 0;
        // cout<<perteam<<endl;

        while(start < end){
            if(skill[start] + skill[end] != perteam) return -1;

            ans += ((skill[start]) * (skill[end]));
            start++;
            end--;
        }

        return ans;
    }
};