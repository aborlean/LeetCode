class Solution {
public:
    bool palindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size(), aux = 0, ma = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(palindrome(s, i, j))
                    if(j - i + 1 > ma) {
                        ma = j - i + 1;
                        aux = i;
                    }

            return s.substr(aux, ma);
    }
};