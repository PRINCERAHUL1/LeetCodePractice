class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> node(n, 0);

        for(int i=0; i<edges.size(); i++)
            node[edges[i][1]]++;
        
        vector<int> res;

        for(int i=0; i<n; i++)
        {
            if(node[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};
