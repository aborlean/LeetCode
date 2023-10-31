class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1)
            return 0;
        int nr = kthGrammar(n - 1, (k + 1) / 2);
        if(k % 2 == 0)
            if(nr == 1)
                return 0;
            else
                return 1;
        return nr;
    }
};