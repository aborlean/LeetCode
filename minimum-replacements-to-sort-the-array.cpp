class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n - 1];
        long long answer = 0;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > last) {
                int aux = nums[i] / last;
                if(nums[i] % last)
                    aux++;
                last = nums[i] / aux;
                answer += aux - 1;
            }
            else
                last = nums[i];
        }

        return answer;
    }
};