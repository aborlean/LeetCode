class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;

        vector<pair<int, int>> v;
        for(int i = 0; i < intervals.size(); i++)
            v.push_back({intervals[i][0], intervals[i][1]});
        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        int start = v[0].first, end = v[0].second;

        for(int i = 0; i < v.size() - 1; i++) {
            vector<int> aux(2);
            if(end >= v[i + 1].first)
                end = max(end, v[i + 1].second);
            else {
                aux[0] = start;
                aux[1] = end;
                start = v[i + 1].first;
                end = v[i + 1].second;
                ans.push_back(aux);
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};