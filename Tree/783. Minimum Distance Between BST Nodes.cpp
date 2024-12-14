class Solution {
public:

    void inorder(TreeNode* root, int &prev, int &res)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, prev, res);
        
        if (prev != -1)
            res = min(res, root->val - prev);

        prev = root->val;

        inorder(root->right, prev, res);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int res = INT_MAX;
        
        inorder(root, prev, res);
        return res;
    }
};
