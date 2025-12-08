class Solution {
public:
    int get1s(int x){
        int cnt = 0;

        while(x > 0){
            x = x & (x-1);
            cnt++;
        }

        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0;i <= n;i++){
            int cnt = get1s(i);
            ans.push_back(cnt);
        }

        return ans;
    }
};