class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool found = false;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast= fast->next->next;

            if(slow == fast)
            {
                found = true;
                break;
            }
        }

        if(!found)
            return NULL;
        
        fast = head;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
