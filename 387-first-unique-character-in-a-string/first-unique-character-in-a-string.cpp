class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        vector<pair<char,int>> orderChars;
        unordered_map<char,int> repeating;
        

        for(int i = 0;i < s.size();i++){
            if(freq.find(s[i]) != freq.end()){
                repeating[s[i]]++;
            }else{
                freq[s[i]]++;
                orderChars.push_back({s[i], i});
            }
        }

        for(auto it : orderChars){
            if(repeating.find(it.first) == repeating.end()){
                return it.second;
            }
        }
        
        return -1;
    }
};