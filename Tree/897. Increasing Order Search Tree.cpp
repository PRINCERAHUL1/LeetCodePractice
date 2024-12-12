class Solution {
public:
    TreeNode* head = new TreeNode(0);
    TreeNode* temp = head;

    void bst(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        bst(root->left);
        head->right = new TreeNode(root->val);
        head = head->right;
        bst(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        bst(root);
        return temp->right;
    }
};
