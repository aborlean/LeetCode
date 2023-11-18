class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> mi(26, INT_MAX);
        vector<int> ma(26, INT_MIN);

        for(int i = 0; i < s.size(); i++) {
            mi[s[i] - 'a'] = min(mi[s[i] - 'a'], i);
            ma[s[i] - 'a'] = max(ma[s[i] - 'a'], i);
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            if((mi[i] == INT_MAX) || ma[i] == INT_MIN)
                continue;

            unordered_set<char> letters;

            for(int j = mi[i] + 1; j < ma[i]; j++)
                letters.insert(s[j]);

            ans += letters.size();
        }

        return ans;
    }
};