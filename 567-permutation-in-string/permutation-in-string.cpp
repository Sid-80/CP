class Solution {
public:
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        if(n>m) return false;
        unordered_map<char,int> ma,mb;
        int i = 0,j = 0;
        while(i<n) ma[a[i++]]++,mb[b[j++]]++;
        if(ma==mb) return true;
        i = 0;
        while(j<m){
            mb[b[j]]++;
            mb[b[i]]--;
            if(mb[b[i]]==0) mb.erase(b[i]);
            if(ma==mb) return true;
            i++, j++;
        }
        return false;

    }
};