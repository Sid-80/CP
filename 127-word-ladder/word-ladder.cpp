class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q; //pair of word and level in bfs
        q.push({beginWord,1});

        unordered_set<string> s(wordList.begin(), wordList.end());

        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if(word == endWord) return lvl;

            for(int i = 0;i < word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end() && original != ch){
                        s.erase(word);
                        q.push({word,lvl+1});
                    }
                }
                word[i] = original;
            }


        }
        return 0;
    }
};