class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n=0;

        if(!head || k == 0)
            return head;
        
        while(temp->next)
        {
            temp = temp->next;
            n++;
        }

        temp->next = head;
         k = k%(n+1);
        int jump = n-k;
        temp = head;

        while(jump)
        {
            temp = temp->next;
            jump--;
        }

        ListNode* returnHead = temp->next;
        temp->next = NULL;

        return returnHead;
    }
};
