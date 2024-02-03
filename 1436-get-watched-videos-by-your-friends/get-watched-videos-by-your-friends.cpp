class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<int> q;
        q.push(id);
        int cnt = -1;
        vector<int> lvlF;
        vector<int> vis(n,-1);
        vis[id] = 1;

        while(!q.empty()){
            int sz = q.size();
            cnt++;

            for(int i = 0;i < sz;i++){
                int front = q.front();
                q.pop();
                for(auto it : friends[front]){
                    if(vis[it] == -1){
                        vis[it] = 1;                        
                        q.push(it);
                    }
                }
                if(cnt == level){
                    lvlF.push_back(front);
                }
            }
            if(cnt == level) break;
        }

        unordered_map<string,int> m;


        for(auto it : lvlF){
            for(auto it2:watchedVideos[it]){
                (m.count(it2)) ? m[it2]++ : m[it2] = 1;
            }
        }

        vector<pair<int,string>> ansPairs;
        for(auto it : m){
            ansPairs.push_back({it.second,it.first});
        }
        sort(ansPairs.begin(),ansPairs.end());

        vector<string> ans;
        for(auto it : ansPairs){
            ans.push_back(it.second);
        }

        return ans;
    }
};