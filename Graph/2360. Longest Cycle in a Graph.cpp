class Solution {
public:

    void dfs(int node, vector<int> &dist_nodes, vector<bool> &visited, vector<int> &edges, int distance, int &res, vector<bool> &extra)
    {
        if(node != -1)
        {
            if(!visited[node])
            {
                visited[node] = true;
                extra[node] = true;
                dist_nodes[node] = distance;
                dfs(edges[node], dist_nodes, visited, edges, distance+1, res, extra);
            }
            else if(extra[node])
                res = max(res, distance-dist_nodes[node]);
            
            extra[node] = false;
        }
    }

    int longestCycle(vector<int>& edges) {
        vector<int> dist_nodes(edges.size(), 0);
        vector<bool> visited(edges.size(), false);
        vector<bool> extra(edges.size(), false);
        int res = -1;

        for(int i=0; i<edges.size(); i++)
        {
            if(!visited[i])
                dfs(i, dist_nodes, visited, edges, 0, res, extra);
        }

        return res;
    }
};
