class Solution {
public:
    bool check(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];

        for(int i = 2; i < arr.size(); i++)
            if(arr[i] - arr[i - 1] != d)
                return false;

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for(int i = 0; i < l.size(); i++) {
            vector<int> aux(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(check(aux));
        }

        return ans;
    }
};