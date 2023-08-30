class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ma = 0, i = 0;
        unordered_map<char, int> m;

        for(int j = 0; j < n; j++) {
            if(m.count(s[j]) == 0 || m[s[j]] < i) {
                m[s[j]] = j;
                ma = max(ma, j - i + 1);
            }
            else {
                i = m[s[j]] + 1;
                m[s[j]] = j;
            }
        }

        return ma;
    }
};