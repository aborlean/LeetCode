class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current = arr[0], count = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > current) {
                current = arr[i];
                count = 1;
            }
            else
                count++;
            if(count == k)
                return current;
        }
        return current;
    }
};