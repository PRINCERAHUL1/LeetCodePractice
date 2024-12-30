class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> visited(rooms.size(), false);
        int n = rooms[0].size();

        for(int i=0; i<n; i++)
            q.push(rooms[0][i]);

        visited[0] = true;

        while(!q.empty())
        {
            int x = q.front();

            if(!visited[x])
            {
                int N = rooms[x].size();

                for(int i=0; i<N; i++)
                {
                    if(!visited[rooms[x][i]])
                        q.push(rooms[x][i]);
                }

                visited[x] = true;
            }

            q.pop();
        }

        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
                return false;
        }

        return true;
    }
};
