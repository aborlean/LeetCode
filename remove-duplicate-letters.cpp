class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26, 0);
        vector<bool> seen(26, 0);
        string ans = "";

        for(char c : s)
            v[c - 'a']++;

        for(char c : s) {
            v[c - 'a']--;
            if(seen[c - 'a'])
                continue;
            while(ans != "" && c < ans.back() && v[ans.back() - 'a'] > 0) {
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            seen[c - 'a'] = true;
        }

        return ans;
    }
};