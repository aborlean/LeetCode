class Solution {
public:
    unordered_map<int, int> m;
    vector<int> ans;
    vector<int> majorityElement(vector<int>& nums) {
        for(int i : nums)
            m[i]++;

        for(auto i : m)
            if(i.second > nums.size() / 3)
                ans.push_back(i.first);

        return ans;
    }
};