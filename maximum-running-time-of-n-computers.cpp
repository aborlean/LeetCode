class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i = 0; i < batteries.size(); i++)
            sum += batteries[i];

        sort(batteries.begin(), batteries.end());

        int i = batteries.size() - 1;
        while(i && sum / n < batteries[i]) {
            sum -= batteries[i];
            n--;
            i--;
        }

        return sum / n;
    }
};