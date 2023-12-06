class Solution {

  bool check(vector<vector<int>>& graph, int i){
    int len = graph.size();
    int arr[len];
    bool ans = true;

    for(int i = 0;i < len;i++){
      arr[i] = -1;
    }

    queue<int> q1; 

    q1.push(i);

    arr[i] = 0;

    while(!q1.empty()){
      int index = q1.front();
      q1.pop();

      for(auto it : graph[index]){
                    
        if(arr[it] == arr[index]){
          return false;
        }else if(arr[it] == -1){
          arr[it] = !arr[index];
          q1.push(it);
        }

      }

    }

    return true;
  }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        for(int i = 0;i < len;i++){
          if(!check(graph,i)) return false;
        }

        return true;

    }
};