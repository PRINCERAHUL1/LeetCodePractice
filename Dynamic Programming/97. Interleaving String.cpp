class Solution {
public:

    bool helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &v)
    {
        if(v[i][j] != -1)
            return v[i][j];

        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;
        
        bool x=false, y=false;
        
        if(i != s1.size())
        {
            if(s1[i] == s3[k])
                x = helper(s1, s2, s3, i+1, j, k+1, v);
        }

        if(j != s2.size())
        {
            if(s2[j] == s3[k])
                y = helper(s1, s2, s3, i, j+1, k+1, v);
        }

        return v[i][j] = x || y;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, -1));
        int i=0, j=0, k=0;
        return helper(s1, s2, s3, 0, 0, 0, v);
    }
};
