class Solution {

    void bfs(vector<int> & vis, int i, vector<vector<int>> rooms){
        
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);

            queue<int> q;
            q.push(0);

            while(!q.empty()){
                int front = q.front();
                q.pop();
                vis[front] = 1;

                for(auto it:rooms[front]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
            }
        

        cout<<vis[0]<<endl;

        for(auto it : vis){
            if(it == 0){ 
                return false;
            }
        }

        return true;
    }
};