class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0)
            return {};
        
        if(n == 1)
            return {new TreeNode(0)};
        
        vector<TreeNode*> res;

        for(int i=0; i<n; i++)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);

            for(TreeNode* l: left)
            {
                for(TreeNode* r: right)
                {
                    res.push_back(new TreeNode(0, l, r));
                }
            }
        }

        return res;
    }
};
