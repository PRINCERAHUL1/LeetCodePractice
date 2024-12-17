class Solution {
public:

    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void mergeVector(vector<int> v1, vector<int> v2, vector<int> &m)
    {
        int i=0, j=0, k=0;

        while(i< v1.size() && j< v2.size())
        {
            if(v1[i] < v2[j])
            {
                m[k] = v1[i];
                i++;
                k++;
            }
            else
            {
                m[k] = v2[j];
                j++;
                k++;
            }
        }

        while(i< v1.size())
        {
            m[k] = v1[i];
            i++;
            k++;
        }
            
        while(j< v2.size())
        {
            m[k] = v2[j];
            j++;
            k++;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return {};
        
        vector<int> tree1, tree2;
        inorder(root1, tree1);
        inorder(root2, tree2);

        vector<int> merged(tree1.size() + tree2.size());
        mergeVector(tree1, tree2, merged);

        return merged;
    }
};
