class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> level;

            for(int i=0; i<levelSize; i++)
            {
                TreeNode* x = q.front();
                q.pop();
                level.push_back(x->val);

                if (x->left)
                    q.push(x->left);
                
                if (x->right)
                    q.push(x->right);
            }

            res.push_back(level);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
