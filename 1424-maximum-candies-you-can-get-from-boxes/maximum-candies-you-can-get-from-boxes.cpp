class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int ans = 0;

        queue<int> q;
        vector<int> boxStatus = status;
        
        for(auto it : initialBoxes){
            q.push(it);
        }

        while(!q.empty()){
            
            int sz = q.size();
            vector<int> temp;

            for(int i = 0;i < sz;i++){
                int node = q.front();
                q.pop();
                
                if(boxStatus[node]){
                    ans+=candies[node];
                    for(auto it : keys[node]){
                        boxStatus[it] = 1;
                    }
                    for(auto it : containedBoxes[node]){
                        q.push(it);
                    }
                }else{
                    temp.push_back(node);
                }
            }
            for(auto it : temp){
                q.push(it);
            }

            if(temp.size() == sz) break;

        }

        return ans;
    }
};