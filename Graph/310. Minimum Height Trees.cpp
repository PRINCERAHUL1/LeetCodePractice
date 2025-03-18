class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> res;

        for(auto e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 1)
            {
                q.push(i);
                indegree[i]--;
            }
        }

        while(!q.empty())
        {
            int s = q.size();
            res.clear();

            for(int i=0; i<s; i++)
            {
                int cur = q.front();
                q.pop();
                res.push_back(cur);

                for(auto x: graph[cur])
                {
                    indegree[x]--;

                    if(indegree[x] == 1)
                        q.push(x);
                }
            }
        }

        if(n == 1)
            res.push_back(0);
        
        return res;
    }
};
