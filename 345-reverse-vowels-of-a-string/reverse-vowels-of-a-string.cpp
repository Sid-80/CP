class Solution {
    bool checkvowel(char x){
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') ? true : false;
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j && i < s.size() && j < s.size()){
            while(!checkvowel(s[i])){
                if(i >= j) break;
                i++;
            }
            while(!checkvowel(s[j])){
                if(i >= j) break;
                j--;
            }
            if(i >= j) break;
            cout<<s[i]<<s[j]<<endl;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }

        return s;
    }
};