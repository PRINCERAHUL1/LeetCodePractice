class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        vector<int> v;
        int count=0;

        while(temp1)
        {
            v.push_back(temp1->val);
            temp1 = temp1->next;
            count++;
        }

        swap(v[k-1], v[count-k]);
        int i=0;

        while(temp2)
        {
            temp2->val = v[i];
            i++;
            temp2 = temp2->next;
        }

        return head;
    }
};
