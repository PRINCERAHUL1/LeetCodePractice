class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        if(n == 0)
            return NULL;
        
        vector<pair<TreeNode*, int>> v;
        int i = 0;

        while(i<n)
        {
            int level = 0;
            while(i<n && traversal[i] == '-')
            {
                level++;
                i++;
            }

            int nodeVal = 0;
            while(i<n && traversal[i] != '-')
            {
                nodeVal = 10*nodeVal + (traversal[i]-'0');
                i++;
            }

            TreeNode* node = new TreeNode(nodeVal);
            v.push_back(make_pair(node, level));

            for(int j=v.size()-2; j>=0; j--)
            {
                if(v[j].second == level-1)
                {
                    if(!v[j].first->left)
                        v[j].first->left = node;
                    else
                        v[j].first->right = node;
                    
                    break;
                }
            }
        }

        return v[0].first;
    }
};
