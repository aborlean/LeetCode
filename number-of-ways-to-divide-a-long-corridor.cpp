class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1, seats = 0, plants = 0;
        const long long mod = 1e9 + 7;

        for(char i : corridor) {
            if(i == 'S')
                seats++;
            else
                if(seats == 2)
                    plants++;

            if(seats == 3) {
                ans = (ans * (plants + 1)) % mod;
                seats = 1;
                plants = 0;
            }
        }

        if(seats != 2)
            return 0;

        return ans;
    }
};