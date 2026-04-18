class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        
        for (int a : aliceSizes) sumA += a;
        for (int b : bobSizes) sumB += b;
        
        int diff = (sumB - sumA) / 2;
        
        unordered_set<int> setB(bobSizes.begin(), bobSizes.end());
        
        for (int a : aliceSizes) {
            if (setB.count(a + diff)) {
                return {a, a + diff};
            }
        }
        
        return {};
    }
};