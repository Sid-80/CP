class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> isvisited;
        unordered_map<char, int> lastOccurance;
        stack<char>st;

        for (int i = 0; i < s.length(); i++) {
            lastOccurance[s[i]] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!isvisited[s[i]]) {

                while (!st.empty() && (st.top() > s[i] && lastOccurance[st.top()] > i)) 
                {
                    isvisited[st.top()] = false;
                    st.pop();
                }
                st.push(s[i]);
                isvisited[s[i]] = true;
            }
        }

        string result="";
        while(!st.empty())
        {
            result=st.top() + result;
            st.pop();
        }
        return result;
    }
};