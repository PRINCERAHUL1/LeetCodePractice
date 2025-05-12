class Solution {
public:

    void helper(int ind, int n, string& res)
    {
        if(ind >= n)
            return;
        
        string prev_val = res;
        res = "";
        int left = 0;
        int count = 0;
        
        for (int right=0; right<prev_val.size(); right++)
        {
            if (prev_val[left] != prev_val[right])
            {
                res += to_string(count) + prev_val[left];
                left = right;
                count = 1;
            }
            else
                count++;
        }
        
        res += to_string(count) + prev_val[left];
        return helper(ind + 1, n, res);
    }

    string countAndSay(int n) {
        string res = "1";
        helper(1, n, res);
        return res;
    }
};
