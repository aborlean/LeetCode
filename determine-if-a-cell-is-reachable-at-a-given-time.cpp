class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy - fy);

        if(t == 1 && x == 0 && y == 0)
            return false;

        int dist = max(x, y);
        return dist <= t;
    }
};