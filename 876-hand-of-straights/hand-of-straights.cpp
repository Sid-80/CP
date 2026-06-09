class Solution {
public:
    // 1, 2, 2, 3, 3, 4, 6, 7, 8

    // 1, 1, 1, 2, 2, 3, 3, 3, 5

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        unordered_map<int,int> mp;
        
        if(n % groupSize != 0) return false;

        for(auto it : hand){
            mp[it]++;
        }

        vector<int> sortedKeys;
        for (auto& pair : mp) {
            sortedKeys.push_back(pair.first);
        }

        sort(sortedKeys.begin(), sortedKeys.end());

        for(auto it : sortedKeys){
            if(mp[it] > 0){
                int startCount = mp[it];

                for(int i = it;i < it + groupSize;i++){
                    if(mp[i] < startCount) return false;

                    mp[i] -= startCount;
                }
            }
        }

        return true;
    }
};