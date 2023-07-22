#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = INT_MIN, i = 0, j = 0;
        map<char,int> m1;

        while(j < s.length()){
            
            if(m1.find(s[j]) == m1.end()){
                m1.insert(pair<char,int>(s[j],1));
            }else{
                m1[s[j]]++;
            }

            if(m1.size() == (j - i + 1) ){

                ans = max(ans,j-i+1);
                j++;

            }else if(m1.size() < (j-i+1)){

                while(m1.size() < (j-i+1)){
                    m1[s[i]]--;
                    if(m1[s[i]] == 0)
                        m1.erase(s[i]);
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout<<s1.lengthOfLongestSubstring(s)<<endl;
    return 0;
}