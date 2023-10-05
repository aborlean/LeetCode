class Solution {
public:
    unordered_map<int, int> m;
    int numIdenticalPairs(vector<int>& nums) {
        int total = 0;
        for(auto i : nums)
            m[i]++;

        for(auto i : m) {
            total += i.second * (i.second - 1) / 2;
        }

        return total;
    }
};