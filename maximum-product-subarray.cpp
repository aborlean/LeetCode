class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int temp_mi = 1, temp_ma = 1, ma = nums[0];

        for(auto i : nums) {
            int old_temp_ma = temp_ma;
            temp_ma = max(temp_ma * i, max(temp_mi * i, i));
            temp_mi = min(old_temp_ma * i, min(temp_mi * i, i));
            ma = max(ma, temp_ma);
        }

        return ma;
    }
};