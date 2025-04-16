class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(102);
        for(int i=0; i<times.size(); i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(105, INT_MAX);
        dist[k] = 0;
        pq.push({dist[k], k});

        while(!pq.empty())
        {
            int pre_dist = pq.top().first;
            int pre_pos = pq.top().second;
            pq.pop();

            for(auto x: adj[pre_pos])
            {
                int next_pos = x.first;
                int next_dist = x.second;

                if(dist[pre_pos] + next_dist < dist[next_pos])
                {
                    dist[next_pos] = dist[pre_pos] + next_dist;
                    pq.push({dist[next_pos], next_pos});
                }
            }
        }

        int mini = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(i!=k && dist[i]==INT_MAX)
                return -1;
            
            mini = max(mini, dist[i]);
        }

        return mini;
    }
};
