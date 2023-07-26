class Solution {
public:

    static bool compare(vector<int>& first, vector<int>& second) {
        return first[1] < second[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1, current = intervals[0][1];

        for(int i = 1; i < n; i++)
            if(current <= intervals[i][0]) {
                count++;
                current = intervals[i][1];
            }

        return n - count;
    }
};