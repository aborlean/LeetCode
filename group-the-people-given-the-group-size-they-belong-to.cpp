class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        for(int i = 0; i < groupSizes.size(); i++) {
            int n = groupSizes[i];
            m[n].push_back(i);

            if(m[n].size() == n) {
                ans.push_back(m[n]);
                m[n].clear();
            }
        }
        return ans;
    }
};