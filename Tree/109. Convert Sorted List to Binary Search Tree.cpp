// Optimized Approach

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) 
            return NULL;
        
        if(head->next == NULL)
            return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;

        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        pre->next = NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// First Approach
/*
class Solution {
public:

    TreeNode* bst(vector<int> v, int l, int r)
    {
        if(l>r)
            return NULL;
        
        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = bst(v, l, mid-1);
        root->right = bst(v, mid+1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        vector<int> v;

        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        return bst(v, 0, v.size()-1);
    }
};
*/
