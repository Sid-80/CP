class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";

        unordered_map<string, int> mp;

        for(auto it : dictionary){
            mp[it] = it.size();
        }

        
        string cur = "";

        for(int i = 0;i < sentence.size();i++){
            if(sentence[i] == ' ' || i == sentence.size() - 1){
                ans += cur;
                if(sentence[i] != ' '){
                    ans += sentence[i];
                } else if(i < sentence.size()){
                    ans += " ";
                }
                cur = "";
            }else{
                cur += sentence[i];
                if(mp.count(cur)){
                    ans+= cur;
                    cout<<cur<<endl;
                    while(sentence[i] != ' ' && i < sentence.size()){
                        i++;
                    }
                    if(i < sentence.size()){
                        ans += " ";
                    }
                    cur = "";
                }
            }
        }

        return ans ;
    }
};