class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s=0;
        double res;

        for(int i=0; i<k; i++)
            s += nums[i];
        
        res=s;
        for(int i=k; i<nums.size(); i++)
        {
            s -= nums[i-k];
            s += nums[i];

            if(res<s)
                res=s;
        }

        return res/k;
    }
};
