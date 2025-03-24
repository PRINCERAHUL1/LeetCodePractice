class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        
        if(dividend==INT_MIN && divisor==1)
            return INT_MIN;
        
        long long dd = abs((long long)dividend);
        long long ds = abs((long long)divisor);
        long long res = 0;

        while(dd >= ds)
        {
            long long sum = ds;
            long long count = 1;

            while(sum+sum <= dd)
            {
                sum += sum;
                count += count;
            }

            res += count;
            dd -= sum;
        }

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            return -res;
        
        return res;
    }
};
