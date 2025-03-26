class Solution {
public:

    bool isDividing(int n)
    {
        int temp = n;
        while(n>0)
        {
            int rem = n%10;

            if(rem==0 || temp%rem != 0)
                return false;
            
            n /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;

        for(int i=left; i<=right; i++)
        {
            if(isDividing(i))
                res.push_back(i);
        }

        return res;
    }
};
