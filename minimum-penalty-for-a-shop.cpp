class Solution {
public:
    int bestClosingTime(string customers) {
        int ma = 0, current = 0, best = -1;
        for(int i = 0; i < customers.size(); i++) {
            if(customers[i] == 'Y')
                current++;
            else
                current--;
            if(current > ma) {
                ma = current;
                best = i;
            }
        }
        return best + 1;
    }
};