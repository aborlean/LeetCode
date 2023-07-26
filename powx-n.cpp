class Solution {
public:
    double exponentiere(double x, int n) {
        if(n == 0)
            return 1;

        double a = exponentiere(x, n / 2);

        if(n % 2 == 0)
            return a * a;
        else
            return x * a * a;
    }
    double myPow(double x, int n) {
        if(n >= 0)
            return exponentiere(x, n);
        else
            return 1/exponentiere(x, n);
    }
};