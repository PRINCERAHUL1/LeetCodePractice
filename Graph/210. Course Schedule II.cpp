class Solution {
public:

    bool dfs(vector<vector<int>> &graph, vector<int> &colors, vector<int> &res, int i)
    {
        colors[i] = 1;

        for(auto neighbour: graph[i])
        {
            if(colors[neighbour] == 1)
                return true;
            
            if(colors[neighbour] == 0)
            {
                if(dfs(graph, colors, res, neighbour))
                    return true;
            }
        }

        colors[i] = 2;
        res.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> colors(numCourses, 0);
        vector<int> res;
        vector<vector<int>> graph(numCourses);

        for(auto pre: prerequisites)
            graph[pre[0]].push_back(pre[1]);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!colors[i])
            {
                if(dfs(graph, colors, res, i))
                    return {};
            }
        }

        return res;
    }
};
