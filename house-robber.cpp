class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0, second = 0;

        for(int i : nums) {
            int aux = max(first + i, second);
            first = second;
            second = aux;
        }

        return second;
    }
};