// Optimal Approach 
// TC: O(n) SC: O(n)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto edge1 = edges[0];
        auto edge2 = edges[1];

        int res = (edge1[0] == edge2[0] || edge1[0] == edge2[1]) ? edge1[0] : edge1[1];

        return res;
    }
};

// Bruteforse Approach
//	TC: O(n) SC: O(n)
/*
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;

        for(auto edge: edges)
        {
            m[edge[0]]++;
            m[edge[1]]++;
        }

        for(auto e: m)
        {
            if(e.second == edges.size())
                return e.first;
        }

        return -1;
    }
};
