class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> maxHeap;
        int n = points.size();
        vector<vector<int>> ans;

        for(int i = 0;i < n;i++){
            double dif = sqrt( pow(points[i][0],2) + pow(points[i][1],2) );
            // cout<<dif<<" "<<points[i][0]<<" "<<points[i][1]<<endl;
            // // double dif = abs(points[i][0] - points[i][1]);

            maxHeap.push( { dif ,{points[i][0],points[i][1]} });

            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            maxHeap.pop();

            ans.push_back({ it.second.first, it.second.second });

        }

        return ans;
    }
};