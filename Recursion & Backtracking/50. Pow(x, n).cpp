class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long temp = n;

        if(n < 0)
            temp = -temp;
        
        while(temp)
        {
            if(temp%2 == 0)
            {
                x = x*x;
                temp /= 2;
            }
            else
            {
                res = res * x;
                temp -= 1;
            }
        }

        if(n < 0)
            res = 1.0/res;
        
        return res;
    }
};
