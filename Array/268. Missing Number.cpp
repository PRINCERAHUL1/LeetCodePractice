class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        int n=nums.size();

        for(int i=0; i<n; i++)
            res ^= (nums[i]^i);
        
        res ^= (n);

        return res;
    }
};
