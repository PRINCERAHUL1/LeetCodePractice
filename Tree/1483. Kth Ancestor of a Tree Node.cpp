class TreeAncestor {
public:

    vector<vector<int>> anc;
    TreeAncestor(int n, vector<int>& parent) {
        anc.resize(16, vector<int>(n, -1));
        anc[0] = parent;

        for (int i=1; i<16; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (anc[i - 1][j] == -1)
                    anc[i][j] = -1;
                else
                    anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i=0; i<16; i++)
        {
            if (node == -1)
                return -1;
            
            if ((1 << i) & k)
                node = anc[i][node];
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
