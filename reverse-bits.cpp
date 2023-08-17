class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans;

        for(int i = 0; i < 32; i++) {
            ans <<= 1;
            bool bit = n & 1;
            ans = ans | bit;
            n >>= 1;
        }

        return ans;
    }
};