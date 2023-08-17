class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int aux = (a & b);
            a ^= b;
            b = aux << 1;
        }

        return a;
    }
};