class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;

        int ans = 0;

        for(auto it : words){
            freq[it]++;
        }

        for(auto it : words){
            string temp = it;
            reverse(temp.begin(), temp.end());

            if(freq.find(temp) != freq.end()){
                if(freq[temp] > 0 && freq[it] > 0 && temp != it){
                    ans += 4;
                    freq[temp] -=1;
                    freq[it] -=1;
                }

                if(freq[temp] > 1 && temp == it){
                    ans+=4;
                    freq[temp] -= 2;
                }
            }
        }


        for(auto it : words){
            string temp = it;
            reverse(temp.begin(), temp.end());

            if(freq.find(temp) != freq.end() && freq[temp] == 1 && temp == it){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};