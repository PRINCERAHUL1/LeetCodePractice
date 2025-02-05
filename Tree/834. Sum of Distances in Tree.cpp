class Solution {
public:

    void dfs(vector<vector<int>> &adj, int u, int p, vector<int> &d, vector<int> &s)
    {
        s[u] = 1;
        for(int v: adj[u])
        {
            if(v == p)
                continue;
            
            d[v] = d[u] + 1;
            dfs(adj, v, u, d, s);
            s[u] += s[v];
        }
    }

    void dfs2(vector<vector<int>> &adj, int u, int p, int distanceSum, vector<int> &s, vector<int> &res, int n)
    {
        res[u] = distanceSum;
        for(int v: adj[u])
        {
            if(v == p)
                continue;
            
            int sdv = distanceSum - s[v] + (n - s[v]);
            dfs2(adj, v, u, sdv, s, res, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d(n, 0);
        vector<int> s(n, 0);
        dfs(adj, 0, -1, d, s);

        int distanceSum = 0;
        for(int i=0; i<n; i++)
            distanceSum += d[i];
        
        vector<int> res(n, 0);
        dfs2(adj, 0, -1, distanceSum, s, res, n);
        
        return res;
    }
};
