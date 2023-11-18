class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> indegree;
        for(auto x : adjacentPairs) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }

        int start;
        for(auto x : indegree) {
            if(x.second == 1) {
                start = x.first;
                break;
            }
        }

        int current = start, p = INT_MIN;
        vector<int> ans;
        while(ans.size() < adjacentPairs.size() + 1) {
            ans.push_back(current);
            for(auto x : g[current])
                if(x != p) {
                    p = current;
                    current = x;
                    break;
                }
        }

        return ans;
    }
};