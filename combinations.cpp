class Solution {
public:
    int v[21];

    void back(int n, int k, int left, vector<int>& comb, vector<vector<int>>& ans) {
        if(comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for(int i = left; i <= n; i++) {
            comb.push_back(i);
            back(n, k, i + 1, comb, ans);
            comb.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        back(n, k, 1, comb, ans);

        return ans;
    }
};