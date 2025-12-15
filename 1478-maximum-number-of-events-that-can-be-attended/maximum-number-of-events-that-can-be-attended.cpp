class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; 

        int ans = 0, i = 0;

        int lastDay = 0;
        for (const auto& e : events) 
        {
            lastDay = max(lastDay, e[1]);
        }

        for(int day = 1; day <= lastDay;day++){
            while(i < n && events[i][0] == day){
                minHeap.push(events[i][1]);
                i++;
            }

            while(!minHeap.empty() && minHeap.top() < day){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                minHeap.pop();
                ans++;
            }

            if(i==n && minHeap.empty()){
                break;
            }
        }


        return ans;
    }
};