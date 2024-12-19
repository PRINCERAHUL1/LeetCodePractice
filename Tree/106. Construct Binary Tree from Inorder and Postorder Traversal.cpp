class Solution {
public:

    TreeNode* helper(vector<int> post, map<int, int> &m, int &rootIdx, int start, int end)
    {
        if(start>end)
            return NULL;
        
        int root = post[rootIdx--];
        int idx = m[root];
        TreeNode* rootNode = new TreeNode(root);

        rootNode->right = helper(post, m, rootIdx, idx+1, end);
        rootNode->left = helper(post, m, rootIdx, start, idx-1);

        return rootNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        
        map<int, int> m;

        for(int i=0; i<inorder.size(); i++)
            m[inorder[i]] = i;
        
        int n = postorder.size()-1;
        TreeNode* root = helper(postorder, m, n, 0, inorder.size()-1);

        return root;
    }
};
