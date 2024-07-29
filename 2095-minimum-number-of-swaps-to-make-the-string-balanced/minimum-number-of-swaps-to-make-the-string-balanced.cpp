class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto&c : s){
            if(c == '['){

                st.push(c);
            }else{ 
                if(!st.empty() && st.top() == '[') {

                    st.pop();
                }else{

                    st.push(c);
                }
            }
        }
        int unmatched = st.size();
        return (unmatched / 2 + 1) / 2;
    }
};