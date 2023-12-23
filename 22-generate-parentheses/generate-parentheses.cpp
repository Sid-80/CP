class Solution {
    void getAns(vector<string> & ans, int open, int close, string paren){
        if(open == 0 && close == 0){
            ans.push_back(paren);
            return;
        }
        // If open == close we have only one choice
        if(open == close){
            string op = paren + '(';
            getAns(ans,open-1,close,op);
        }else if(open == 0){
            string op = paren + ')';
            getAns(ans,open,close-1,op); 
        }else if(close == 0){
            string op = paren + '(';
            getAns(ans,open - 1,close,op); 
        }else{
            string op1 = paren + '(';
            string op2 = paren + ')';
            getAns(ans,open - 1,close,op1);
            getAns(ans,open,close-1,op2); 
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        getAns(ans,n,n,"");

        return ans;

    }
};