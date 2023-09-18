class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)
            return a.second < b.second;
        return false;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        vector<int> ans;


        for(int i = 0; i < mat.size(); i++) {
            int count = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j])
                    count++;
            }
            v.push_back({count, i});
        }

        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < k; i++)
            ans.push_back(v[i].second);

        return ans;
    }
};