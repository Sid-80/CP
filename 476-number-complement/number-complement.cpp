class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        unsigned int mask = ~0;
        
        while (num & mask) {
            cout<<(num & mask)<<endl;
            mask <<= 1;
        }
        
        return ~mask & ~num;
    }
};