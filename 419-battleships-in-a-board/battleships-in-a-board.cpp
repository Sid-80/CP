class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        int ans = 0;
        if(board[0][0] == 'X') ans+=1;

        for(int i = 1;i < m;i++){
            if(board[0][i] == 'X'){
                ans+=1;
                if(board[0][i-1] == 'X'){
                    ans-=1;
                }
            }
        }


        for(int i = 1;i < n;i++){
            if(board[i][0] == 'X'){
                ans+=1;
                if(board[i-1][0] == 'X'){
                    ans-=1;
                }
            }
        }

        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                if(board[i][j] == 'X'){
                    ans+=1;
                    if(board[i-1][j] == 'X' || board[i][j-1] == 'X'){
                        ans-=1;
                    }
                }
            }
        }

        return ans;
        
    }
};