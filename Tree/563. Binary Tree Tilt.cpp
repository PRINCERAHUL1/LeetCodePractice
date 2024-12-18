class Solution {
public:
    int res = 0;

    int helper(TreeNode* root)
    {
        int left = root->left ? helper(root->left) : 0;
        int right = root->right ? helper(root->right) : 0;
        
        res += abs(left - right);
        return (left+right+root->val);
    }

    int findTilt(TreeNode* root) {
        if(!root)
            return NULL;
        
        helper(root);
        return res;
    }
};
