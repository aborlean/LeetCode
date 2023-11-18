class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time(dist.size());

        for(int i = 0; i < dist.size(); i++)
            time[i] = (double)(dist[i]) / speed[i];

        sort(time.begin(), time.end());

        for(int i = 0; i < dist.size(); i++)
            if(time[i] <= i)
                return i;

        return dist.size();
    }
};