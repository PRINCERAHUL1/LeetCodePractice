class Solution {
public:
    unordered_map<int, int> mp;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            mp[root->val]++;
            inorder(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        int maxi = 0;
        vector<int> res;

        for(auto i: mp)
        {
            if(i.second > maxi)
                maxi = i.second;
        }

        for(auto i: mp)
        {
            if(maxi == i.second)
                res.push_back(i.first);
        }

        return res;
    }
};
