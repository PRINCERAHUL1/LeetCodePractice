class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        int maxindex = 0;
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]>nums[maxindex])
                maxindex = i;
        }
        
        for(int i =0;i<nums.size();i++)
        {
            if(i!= maxindex && nums[maxindex] < 2 *nums[i])
                return -1;
        }

        return maxindex;
    }
};
