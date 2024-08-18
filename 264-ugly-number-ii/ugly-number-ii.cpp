class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long, vector<long long>, greater<long long>> minq;

        minq.push(1);
        long ans = 0;
        for(int i = 0;i < n;i++){
            while(ans == minq.top()){
                minq.pop();
            }
            ans = minq.top();
            minq.pop();
            minq.push(ans*2);
            minq.push(ans*3);
            minq.push(ans*5);
        }
        return ans;
    }
};