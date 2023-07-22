#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0;
        string ans;
        int ansLen = INT_MAX;

        if(t.length() == 1){
            for (int k = 0; k < s.length(); k++)
            {
                if(s[k] == t[0])
                    return t;
            }
            return ""; 
        }

        if(s.length() < t.length()){
            return "";
        }else if( s == t){
            return s;
        }else if(s.length() < t.length() && s != t){
            return "";
        }

        map<char, int> m1;
        for (int k = 0; k < t.length(); k++)
        {
            if (m1.find(t[k]) == m1.end())
            {
                m1.insert(pair<char, int>(t[k], 1));
            }
            else
            {
                m1[t[k]]++;
            }
        }
        int count = m1.size();

        while (j < s.length())
        {
            if (m1.find(s[j]) != m1.end())
            {
                m1[s[j]]--;
                if (m1[s[j]] == 0)
                    count--;
            }
            if (count == 0)
            {
                bool t = true;
                while (t)
                {
                    if(m1.count(s[i]) == 0){
                        i++;
                    }else if(m1.count(s[i]) == 1 && m1[s[i]] < 0){
                        m1[s[i]]++;
                        i++;
                    }else{
                        t = false;
                    }
                    
                }
                if (ansLen >= (j - i + 1))
                {
                    ans = s.substr(i, (j - i + 1));
                    ansLen = j - i + 1;
                }
                if(m1.find(s[i]) != m1.end()){
                    m1[s[i]]++;
                }
                if (m1[s[i]] > 0)
                {
                    count++;
                }
                i++;
                while(m1.find(s[i]) == m1.end()){
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};



int main(int argc, char const *argv[])
{
    Solution s1;
    cout << s1.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s1.minWindow("abc", "bc");
    return 0;
}