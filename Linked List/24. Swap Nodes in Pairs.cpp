class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        int count =0;

        while(cur != NULL && count <2)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
            count++;
        }

        head->next = swapPairs(nex);

        return pre;
    }
};
