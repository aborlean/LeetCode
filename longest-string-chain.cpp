class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> m;
        int count = 0;

        for(string word : words) {
            int ma = 0;
            for(int i = 0; i < word.length(); i++) {
                string aux = word;
                aux.erase(i, 1);
                ma = max(ma, m[aux] + 1);
            }
            m[word] = ma;
            count = max(count, ma);
        }

        return count;
    }
};