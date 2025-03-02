class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> uniqueNums(nums.begin(), nums.end());

        if (uniqueNums.size() < 3) 
            return *uniqueNums.rbegin();

        auto it = uniqueNums.rbegin();
        advance(it, 2);
        
        return *it;
    }
};
