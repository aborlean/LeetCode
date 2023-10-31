class Solution {
public:
    static bool s(int a, int b) {
        int count_a = 0, count_b = 0, x = a, y = b;

        while(a) {
            if(a % 2 == 1)
                count_a++;
            a /= 2;
        }

        while(b) {
            if(b % 2 == 1)
                count_b++;
            b /= 2;
        }

        if(count_a > count_b)
            return false;
        else if(count_a == count_b && x > y)
            return false;
        return true;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), s);
        return arr;
    }
};