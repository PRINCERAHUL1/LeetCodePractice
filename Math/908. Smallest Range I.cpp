class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int n: nums)
        {
            maxi = max(maxi, n);
            mini = min(mini, n);
        }

        int smallestDiff = (maxi - mini) - (2*k);
        return (smallestDiff<=0) ? 0 : smallestDiff;
    }
};
