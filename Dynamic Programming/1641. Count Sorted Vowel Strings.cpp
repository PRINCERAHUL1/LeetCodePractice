class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        int res = 0;
        
        while(--n)
        {
            for(int i=3; i>=0; i--)
                dp[i] += dp[i+1];
        }

        for(auto i: dp)
            res += i;
        
        return res;
    }
};


//class Solution {
//public:
//
//    void solve(int n, int last, int &count)
//    {
//        if(n==0)
//        {
//            count++;
//            return;
//        }
//
//        for(int i=0; i<5; i++)
//        {
//            if(i >= last)
//                solve(n-1, i, count);
//        }
//    }
//
//    int countVowelStrings(int n) {
//        int count = 0;
//        solve(n, 0, count);
//        return count;
//    }
//};
