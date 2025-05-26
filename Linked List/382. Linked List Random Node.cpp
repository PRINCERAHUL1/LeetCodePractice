class Solution {
public:

    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
    }
    
    int getRandom() {
        int count = 0;
        int res = 0;
        ListNode* curr = head;
        
        while (curr)
        {
            count++;
            if (rand() % count == 0)
                res = curr->val;
        
            curr = curr->next;
        }
        
        return res;
    }
};
