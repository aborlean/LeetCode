class Solution {
public:
    vector<int> ans;
    vector<int> start;
    vector<int> bloom;
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        for(auto x : flowers) {
            start.push_back(x[0]);
            bloom.push_back(x[1]);
        }

        sort(start.begin(), start.end());
        sort(bloom.begin(), bloom.end());

        for(int i = 0; i < people.size(); i++) {
            int before = start.size() - (upper_bound(start.begin(), start.end(), people[i]) - start.begin());
            int after = bloom.size() - (lower_bound(bloom.begin(), bloom.end(), people[i]) - bloom.begin());
            ans.push_back(after - before);
        }

        return ans;
    }
};