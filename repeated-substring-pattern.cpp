class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n / 2; i++) {
            if(n % i == 0) {
                string s2 = s.substr(0, i);
                string aux = "";
                for(int j = 0; j < n / i; j++)
                    aux += s2;
                if(aux == s)
                    return true;
            }
        }
        return false;
    }
};