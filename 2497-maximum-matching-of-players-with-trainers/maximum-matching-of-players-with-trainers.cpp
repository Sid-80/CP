class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n1 = players.size(), n2 = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;

        int i = n2 - 1;

        // 4, 7, 9
        // 2, 5, 8, 8

        for(int j = n1 - 1;j >= 0;j--){
            if(trainers[i] >= players[j]){
                ans++;
                i--;
            }
            if(i < 0) break;
        }


       return ans;
    }
};