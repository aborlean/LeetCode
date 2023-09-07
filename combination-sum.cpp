class Solution {
public:
    vector<vector<int>> ans;
    void search(vector<int>& candidates, int total, int cnt, vector<int>& current, int k) {
        if(cnt == total) {
            ans.push_back(current);
            return;
        }
        if(cnt > total)
            return;
        for(int i = k; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            search(candidates, total, cnt + candidates[i], current, i);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        search(candidates, target, 0, current, 0);
        return ans;
    }
};