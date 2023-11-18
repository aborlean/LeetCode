class Solution {
public:
    string ans;
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i][i] == '1')
                ans += '0';
            else
                ans += '1';
        }
        return ans;
    }
};