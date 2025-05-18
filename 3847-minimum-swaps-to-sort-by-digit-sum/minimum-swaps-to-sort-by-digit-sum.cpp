class Solution {
public:
    int getSum(int num){
        int sum = 0;

        while(num > 0){
            sum += num%10;
            num = num/10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> v = nums;

        sort(v.begin(), v.end(), [&](int a , int b ){
            int sumA = getSum(a);
            int sumB = getSum(b);
            if(sumA == sumB) return a < b;
            return sumA < sumB;
        });

        unordered_map<int,int> m;
        for(int i = 0;i < n;i++){
            m[nums[i]] = i;
        }
        
        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i = 0;i < n;i++){
            if(vis[i] || v[i] == nums[i]) continue;

            int cycle_size = 0;
            int j = i;

            while(!vis[j]){
                vis[j] = true;
                j = m[v[j]];
                cycle_size++;
            }

            if(cycle_size > 1){
                cnt += (cycle_size - 1);
            }
        }

        return cnt;
    }
};