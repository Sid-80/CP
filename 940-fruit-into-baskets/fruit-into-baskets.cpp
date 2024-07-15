class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, n = fruits.size(), start = 0;

        unordered_map<int,int> m;

        for(int end = 0; end < n;end++){
            m[fruits[end]]++;


            if(m.size() <= 2){
                ans = max(ans,end-start+1);
            }else{
                while(m.size() > 2){
                    m[fruits[start]]--;
                    
                    if(m[fruits[start]] == 0) m.erase(fruits[start]);
                    start++;
                }
            }

        }

        return ans;
    }
};