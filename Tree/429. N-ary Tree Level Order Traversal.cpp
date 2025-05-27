class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};

        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i<n; i++)
            {
                auto front = q.front();
                q.pop();
                temp.push_back(front->val);

                for (auto child : front->children)
                    q.push(child);
            }

            res.push_back(temp);
        }

        return res;
    }
};
