class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mi = 0, ma = 0, used = 0;
        while(ma < n) {
            for(int i = 0; i < ranges.size(); i++)
                if(i - ranges[i] <= mi && i + ranges[i] >= ma)
                    ma = i + ranges[i];
            if(ma == mi)
                return -1;
            used++;
            mi = ma;
        }
        return used;
    }
};