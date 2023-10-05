class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;

        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;

        while(i < n && j < m)
            if(nums1[i] < nums2[j])
                nums.push_back(nums1[i++]);
            else
                nums.push_back(nums2[j++]);

        while(i < nums1.size())
            nums.push_back(nums1[i++]);
        while(j < nums2.size())
            nums.push_back(nums2[j++]);

        int mi = nums.size() / 2;

        if(nums.size() % 2 == 0)
            return (nums[mi - 1] + nums[mi]) / 2.0;
        else
            return nums[mi];
    }
};