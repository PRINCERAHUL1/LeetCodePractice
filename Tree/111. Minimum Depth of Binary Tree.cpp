// Optimized Code
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;

        if(root -> right == NULL)
            return 1 + minDepth(root->left);

        if(root -> left == NULL)
            return 1 + minDepth(root->right);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

/* My Code
class Solution {
public:

    void bt(TreeNode* root, int &res, int count)
    {
        if(root == NULL)
            return;
        
        if (root->left == NULL && root->right == NULL)
            res = min(res, count);

        bt(root->left, res, count+1);
        bt(root->right, res, count+1);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res= INT_MAX;
        int count= 1;

        bt(root, res, count);

        return res;        
    }
};
*/
