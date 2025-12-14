class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n=nums.size();
        long long modP=accumulate(nums.begin(), nums.end(), 0LL)%p;

        if (modP==0) return 0;
        int sz=min(n, p);

        unordered_map<int, int> pos={{0, -1}};
        pos.reserve(sz);

        int len=n, sumP=0;
        for(int i=0; i<n; i++){
            sumP=(sumP+nums[i])%p;
            int y=(sumP-modP+p)%p;

            // cout<<sumP<<" "<<y<<endl;

            if (pos.count(y))
                len=min(len, i-pos[y]);
            pos[sumP]=i;
        }
        return (len==n)?-1:len;
    } 
};