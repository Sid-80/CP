class Solution {
    vector<vector<string>> ans;
    unordered_map<string,int> m; // string and its lvl

    void dfs(string word, vector<string> & seq, string beginWord){
        if(word == beginWord) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int lvl = m[word];
        int size = word.size();

        for(int i = 0;i < size;i++){
            char org = word[i];
            for(char ch = 'a';ch <= 'z';ch++){
                word[i] = ch;
                if(m.find(word) != m.end() && m[word] + 1 == lvl){
                    seq.push_back(word);
                    dfs(word,seq,beginWord);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }

    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // unordered_set<string> s(wordList.begin(),wordList.end());
        // queue<vector<string>> q;
        // vector<vector<string>> ans;

        // q.push({beginWord});

        // vector<string> usedOnLevel;
        // usedOnLevel.push_back(beginWord);
        // int lvl = 0;

        // while(!q.empty()){
            
        //     vector<string> str = q.front();
        //     q.pop();

        //     if(str.size() > lvl){
        //         lvl++;
        //         for(auto it : usedOnLevel){
        //             s.erase(it);
        //         }
        //         usedOnLevel.clear();
        //     }

        //     string word = str.back();

        //     if(word == endWord){
        //         if(ans.size() == 0) ans.push_back(str);
        //         else if(ans[0].size() == str.size()){
        //             ans.push_back(str);
        //         }
        //     }

        //     for(int i = 0;i < word.size();i++){
        //         char org = word[i];
        //         for(char c = 'a';c <= 'z';c++){
        //             word[i] = c;
        //             if(s.count(word) > 0 && org != c){
        //                 str.push_back(word);
        //                 q.push(str);
        //                 usedOnLevel.push_back(word);
        //                 str.pop_back();
        //             }
        //         }
        //         word[i] = org;
        //     }

        // }

        // return ans;

        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push({beginWord}); 
            

        m[beginWord] = 1;
        int size = beginWord.size();
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int lvl = m[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0;i < size;i++){
                char org = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    if(s.count(word) >0 && ch != org){
                        q.push(word);
                        s.erase(word);
                        m[word] = lvl + 1;
                    }
                }
                word[i] = org;
            }
        }
        
        if(m.find(endWord) != m.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq,beginWord);
        }

        return ans;

    }
};