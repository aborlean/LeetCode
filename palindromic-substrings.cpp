class Solution {
public:
    bool palindrome(string s) {
        int i = 0, n = s.size() - 1;
        while(i <= n)
            if(s[i++] != s[n--])
                return false;
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(palindrome(s.substr(i, j - i + 1)))
                    count++;
        return count;
    }
};