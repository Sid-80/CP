class Solution {
public:
    // nums1[i] * nums1[i] = nums2[j] * nums2[k]

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        unordered_map<long long, long long> freq1, freq2;

        int ans = 0;

        for(auto it: nums1){
            long long t = 1LL * it * it;
            freq1[t]++;
        }
        
        for(auto it: nums2){
            long long t = 1LL * it * it;
            freq2[t]++;
        }

        for(int i = 0;i < n1;i++){
            for(int j = i + 1;j < n1;j++){

                long long x = 1LL * nums1[i] * nums1[j];
                if(freq2.find(x) != freq2.end()){
                    ans += freq2[x];
                }

            }
        }

        for(int i = 0;i < n2;i++){
            for(int j = i + 1;j < n2;j++){

                long long x = 1LL * nums2[i] * nums2[j];
                if(freq1.find(x) != freq1.end()){
                    ans += freq1[x];
                }

            }
        }


        return ans;
    }
};