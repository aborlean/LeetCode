#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool time(vector<int>& dist, int speed, double hour) {
        double value = 0;
        for(int i = 0; i < dist.size(); i++) {
            double distance = double(dist[i]) / speed;
            if(i == dist.size() - 1)
                value += distance;
            else
                value += ceil(distance);
        }

        return value <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 10000000, mid, minspeed = -1;
        while(left <= right) {
            mid = (left + right) / 2;
            if(time(dist, mid, hour)) {
                minspeed = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return minspeed;
    }
};

int main(void)
{
    Solution* s = new Solution();

    int arr[] = {1, 3, 2};

    vector<int> vect(arr, arr + 3);

    cout << s->minSpeedOnTime(vect, 6);

    return 0;
}