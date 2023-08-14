class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            anagrams[key].push_back(strs[i]);
        }

        for(auto i : anagrams)
            ans.push_back(i.second);

        return ans;
    }
};