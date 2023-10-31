class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 || n == 2 || (n & (n - 1)))
            return false;

        int cnt = 0;

        while(n) {
            n >>= 1;
            cnt++;
        }

        return cnt % 2;
    }
};

