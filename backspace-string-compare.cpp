class Solution {
public:
    int operation(string& s) {
        int n = 0;

        for(char c : s) {
            if(c != '#') {
                s[n++] = c;
            }
            else if(n > 0)
                n--;
        }

        return n;
    }
    bool backspaceCompare(string s, string t) {
        int k = operation(s);
        int p = operation(t);

        if(k != p)
            return false;

        for(int i = 0; i < k; i++)
            if(s[i] != t[i])
                return false;

        return true;
    }
};