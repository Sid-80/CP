// John is at a toy store help him pick maximum number of toys. 
// He can only select in a continuous manner and he can select only two types of toys.

// Example:
// Input:
// 1
// abaccab


#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout<<"Enter string : ";cin>>s;

    int ans = INT_MIN;
    int i = 0, j = 0;
    map<char,int> m1;

    int toysN = 2;

    while(j < s.length()){

        if(m1.find(s[j]) == m1.end()){
            m1.insert(pair<char,int>(s[j],1));
        }else{
            m1[s[j]]++;
        }

        if(m1.size() == toysN){
            ans = max(ans,(j-i+1));
            j++;
        }else if(m1.size() < toysN){
            j++;
        }else if(m1.size() > toysN){
            while(m1.size() > toysN){
                m1[s[i]]--;
                if(m1[s[i]] == 0)
                    m1.erase(s[i]);
                i++;
            }
            j++;
        }
    }

    cout<<ans<<endl;

    return 0;
}