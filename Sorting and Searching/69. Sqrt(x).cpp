class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        long long res = 0;

        while(l <= r)
        {
            long long mid = l + (r-l)/2;

            if(mid*mid == x)
            {
                res = mid;
                break;
            }
            else if(mid*mid < x)
            {
                l = mid+1;
                res = mid;
            }
            else
                r = mid-1;
        }

        return res;
    }
};
