class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0;
    }
};

//class Solution {
//public:
//    bool divisorGame(int n) {
//        if(n==1)
//            return false;
//        
//        vector<int> dp(1001, 0);
//        dp[2] = 1;
//
//        for(int i=0; i<=n; i++)
//        {
//            for(int j=1; j*j<=i; j++)
//            {
//                if(i%j==0 && dp[i-j]==0)
//                    dp[i] = 1;
//            }
//        }
//
//        return dp[n];
//    }
//};
