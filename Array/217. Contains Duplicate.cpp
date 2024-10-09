class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(int n:nums)
        {
            if(m[n] >= 1)
                return true;
            
            m[n]++;
        }

        return false;
    }
};
