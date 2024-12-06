class Solution {
public:
    int pairSum(ListNode* head) {
        if(head == NULL)
            return 0;
        
        vector<int> v;

        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        int maxi = 0;

        for(int i=0; i<n/2; i++)
            maxi = max(maxi, v[i]+v[n-1-i]);
        
        return maxi;
    }
};
