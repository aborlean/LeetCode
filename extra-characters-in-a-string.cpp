class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector <int> dp(s.length() + 1, s.length() + 1);
        dp[0] = 0;

        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        for(int i = 1; i <= s.length(); i++) {
            dp[i] = dp[i - 1] + 1;
            for(int k = 1; k <= i; k++)
                if(dict.find(s.substr(i - k, k)) != dict.end())
                    dp[i] = min(dp[i], dp[i - k]);
        }

        return dp.back();
    }
};