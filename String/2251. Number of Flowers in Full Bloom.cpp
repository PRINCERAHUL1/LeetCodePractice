class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> startTime;
        vector<int> endTime;
        vector<int> res;
        
        for(auto flower: flowers)
        {
            startTime.push_back(flower[0]);
            endTime.push_back(flower[1]);
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        for(int p: people)
        {
            int upper = upper_bound(startTime.begin(), startTime.end(), p) - startTime.begin();
            int lower = lower_bound(endTime.begin(), endTime.end(), p) - endTime.begin();
            res.push_back(upper-lower);
        }

        return res;
    }
};
