class Solution {

public:

        int get1s(int x){
        int cnt = 0;

        while(x > 0){
            x = x & (x-1);
            cnt++;
        }

        return cnt;
    }

    int hammingWeight(int n) {
        return get1s(n);
    }
};