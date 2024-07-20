class Solution {
public:

    int nextGreaterElement(int n) {
        string s = to_string(n);

        int pivot = s.size()-1;

        while (pivot > 0 && s[pivot-1] >= s[pivot]) pivot--;

        if(pivot == 0) return -1;

        int j = s.size()-1;
        while (j > 0 && s[pivot-1]>=s[j]) j--;
        
        swap(s[pivot-1],s[j]);

        reverse(s.begin()+pivot,s.end());

        size_t ans = stoll(s);

        return (ans > INT_MAX ) ? -1 : ans;
    }
};