class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n+1, 1);
        int right = 1;

        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1]+1;
        }

        for(int j=n-2; j>=0; j--)
        {
            if(ratings[j] > ratings[j+1])
            {
                right++;
                left[j] = max(left[j], right);
            }
            else
                right = 1;
        }

        int res = 0;
        for(int i=0; i<n; i++)
            res += left[i];
        
        return res;
    }
};
