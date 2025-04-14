class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        while(low+1 < nums.size() && nums[low] <= nums[low+1])
            low++;
        
        while(high-1 >= 0 && nums[high-1] <= nums[high])
            high--;
        
        if(low == nums.size()-1)
            return 0;
        
        for(int i=low; i<=high; i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        while(low-1 >= 0 && nums[low-1] > mini)
            low--;
        
        while(high+1 < nums.size() && nums[high+1] < maxi)
            high++;
        
        return high-low+1;
    }
};
