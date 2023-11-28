class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        long long ans = 0, current = 0;

        ans += garbage[0].size();

        vector<int> last(4, -1);

        for(int house = 1; house < garbage.size(); house++) {
            ans += garbage[house].size();

            if(garbage[house].find("M") != garbage[house].npos)
                last[0] = house - 1;
            if(garbage[house].find("P") != garbage[house].npos)
                last[1] = house - 1;
            if(garbage[house].find("G") != garbage[house].npos)
                last[2] = house - 1;
        }

        for(int i = 0; i < travel.size(); i++) {
            current += travel[i];

            for(int truck = 0; truck < 3; truck++)
                if(last[truck] == i)
                    ans += current;
        }

        return ans;
    }
};