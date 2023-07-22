// COUNT OCCURENCES OF ANAGRAM
// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.
// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string txt, pat;
    cout << "Enter the text : ";
    cin >> txt;
    cout << "Enter the pattern : ";
    cin >> pat;

    map<char, int> m1;

    for (int i = 0; i < pat.length(); i++)
    {
        if (m1.find(pat[i]) == m1.end())
        {
            m1.insert(pair<char, int>(pat[i], 1));
        }
        else
        {
            m1[pat[i]] = m1[pat[i]]++;
        }
    }

    int count = m1.size();

    int i = 0, j = 0;
    int ans = 0;

    while (j != txt.length() - 1)
    {
        if ((j - i + 1) < pat.length())
        {
            if (m1.find(txt[j]) != m1.end())
            {
                m1[txt[j]]--;
                if (m1[txt[j]] == 0)
                    count--;
            }
            j++;
        }
        else if ((j - i + 1) == pat.length())
        {
            if (count == 0)
                ans++;

            if (m1.find(txt[i]) != m1.end())
            {
                m1[txt[i]]++;
            }
            if (m1[txt[i]] == 1)
                count++;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}