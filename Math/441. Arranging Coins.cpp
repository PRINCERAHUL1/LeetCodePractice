class Solution {
public:
    int arrangeCoins(int n) {
        if(n <=1)
            return n;
        
        int left = 1;
        int right = n;

        while(left<=right)
        {
            long long mid = left + (right-left)/2;
            long long s = mid*(mid+1)/2;

            if(s>n)
                right = mid-1;
            else
                left = mid+1;
        }

        return left-1;
    }
};


//class Solution {
//public:
//    int arrangeCoins(int n) {
//        int rowCount = 0;
//
//        while(n>0)
//        {
//            rowCount++;
//            n -= rowCount;
//        }
//
//        return (n==0) ? rowCount : rowCount-1;
//    }
//};
