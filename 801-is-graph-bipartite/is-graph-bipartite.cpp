class Solution
{

    bool checkBFS(vector<vector<int>> &graph, int i)
    {
        int len = graph.size();
        int arr[len];

        for (int i = 0; i < len; i++)
        {
            arr[i] = -1;
        }

        queue<int> q1;

        q1.push(i);

        arr[i] = 0;

        while (!q1.empty())
        {
            int index = q1.front();
            q1.pop();

            for (auto it : graph[index])
            {

                if (arr[it] == arr[index])
                {
                    return false;
                }
                else if (arr[it] == -1)
                {
                    arr[it] = !arr[index];
                    q1.push(it);
                }
            }
        }

        return true;
    }

    bool checkDFS(int node, int arr[], vector<vector<int>> graph, int color){
      arr[node] = color;

      for(auto it : graph[node]){
        
        if(arr[it] == -1){
          if(!checkDFS(it,arr,graph,!color)){ 
            return false;
          }
        }
        else if(arr[it] == color){ 
          return false;
        };

      }
      
      return true;
    }


public:
    bool isBipartite(vector<vector<int>> &graph)
    {
      int len = graph.size();

       int arr[len];

      for (int i = 0; i < len; i++){
        arr[i] = -1;
      }

      for (int i = 0; i < len; i++){
        if (arr[i] == -1 && !checkDFS(i,arr,graph,0)) return false;
      }

      return true;
    }
};