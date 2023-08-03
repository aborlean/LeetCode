class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            int dif = target - nums[i];
            if(map.count(dif))
                return {map[dif], i};
            map[nums[i]] = i;
        }

        return {};
    }
};