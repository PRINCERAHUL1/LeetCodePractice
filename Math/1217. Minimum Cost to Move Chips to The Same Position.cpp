class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even  = 0;
        int odd = 0;
        int res = 0;

        for(int i=0; i<position.size(); i++)
        {
            if(position[i]%2 == 0)
                even++;
            else
                odd++;
        }

        res = min(even, odd);
        return res;
    }
};
