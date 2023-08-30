class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto i : nums)
            map[i]++;

        priority_queue<pair<int, int>> q;

        for(auto i : map)
            q.push({i.second, i.first});

        vector<int> v;

        while(k--) {
            v.push_back(q.top().second);
            q.pop();
        }

        return v;
    }
};