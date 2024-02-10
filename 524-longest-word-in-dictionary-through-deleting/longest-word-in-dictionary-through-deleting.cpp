class Solution {
    bool check(string word, string s){
        int i = 0, j = 0;

        while(i < word.size() && j < s.size()){
            
            if(word[i] == s[j]){
                i++;
            }
            j++;
        }

        return i == word.size();
    }

public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(auto it:dictionary){
            if(check(it,s)){
              
                    if(it.size() > ans.size() || (it.size() == ans.size() && it < ans)){
                        ans = it;
                    }
            
            }
        }

        return ans;

    }
};