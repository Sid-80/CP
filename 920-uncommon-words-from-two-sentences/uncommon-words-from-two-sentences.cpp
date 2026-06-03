class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        string word="";
        unordered_map<string,int>m;
        for(char c :s1){
            if(isalpha(c)){
                word+=c;
            }else{
                m[word]++;
                word="";
            }
        }
        if(word!="") m[word]++;
        word="";
          for(char c :s2){
            if(isalpha(c)){
                word+=c;
            }else{
                m[word]++;
                word="";
            }
        }
        if(word!="") m[word]++;
        for(auto it:m){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};