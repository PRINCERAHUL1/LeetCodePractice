class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;

        for(int i=0; i<queries.size(); i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int cx = 0, cy = 0;

            while(x != y)
            {
                if(x>y)
                {
                    cx++;
                    x /= 2;
                }
                else
                {
                    cy++;
                    y /= 2;
                }
            }

            res.push_back(cx+cy+1);
        }

        return res;
    }
};
