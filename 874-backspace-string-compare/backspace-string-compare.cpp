class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1;
        stack<int> s2;

        int i = 0, j = 0;
        int n1 = s.size(), n2 = t.size();

        while(i < n1 && j < n2){
            if(s[i] == '#' && !s1.empty()){
                s1.pop();
            }else if(s[i] != '#'){
                s1.push(s[i]);
            }
            if(t[j] == '#' && !s2.empty()){
                s2.pop();
            }else if(t[j] != '#'){
                s2.push(t[j]);
            }
            i++;
            j++;
        }

        while(i < n1){
            if(s[i] == '#' && !s1.empty()){
                s1.pop();
            }else if(s[i] != '#') {
                s1.push(s[i]);
            }
            i++;
        }

        
        while(j < n2){
            if(t[j] == '#' && !s2.empty() ){
                s2.pop();
            }else if(t[j] != '#') {
                s2.push(t[j]);
            }
            j++;
        }

        return (s1 == s2);
    }
};