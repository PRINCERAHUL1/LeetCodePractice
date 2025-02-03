class Solution {
public:
    int res = INT_MIN;

    int dfs(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        int sum = root->val + l + r;

        res = max(res, sum);
        return root->val+max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
