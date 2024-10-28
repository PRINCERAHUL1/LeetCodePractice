class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int, int> m;

        for(int n : nums)
        {
            res += m[n];

            m[n]++;
        }

        return res;
    }
};
