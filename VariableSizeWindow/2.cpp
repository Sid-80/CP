// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
// If there is no possible substring then print -1.

// Input:
// S = "aabacbebebe", K = 3
// Output: 7
// Explanation: "cbebebe" is the longest 
// substring with K distinct characters.

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    int K;
    cout<<"Enter no. of unique characters : ";
    cin>>K;

    int ans = INT_MIN;

    map<char,int> m1;
    int i = 0, j = 0;

    while (j < s.length())
    {

        if(m1.find(s[j]) == m1.end()){
            m1.insert(pair<char,int>(s[j],1));
        }else{
            m1[s[j]]++;
        }

        if(m1.size() > K){

            while(m1.size() > K){
                m1[s[i]]--;
                if(m1[s[i]] == 0)
                    m1.erase(s[i]); 
                i++;
            }
            j++;

        }else if(m1.size() == K){
            
            ans = max(ans,(j-i+1));
            j++;

        }else if(m1.size() < K){
            j++;
        }
    }

    cout<<ans<<endl;

    return 0;
}