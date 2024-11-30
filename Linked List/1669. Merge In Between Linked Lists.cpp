class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list1 && !list2)
            return NULL;
        
        if(list1 && !list2)
            return list1;
        
        if(!list1 && list2)
            return list2;
        
        ListNode* left = NULL;
        ListNode* right = list1;
        ListNode* temp = list2;
        
        for(int i=0; i<=b; i++)
        {
            if(i == a-1)
                 left = right;
            
            right = right->next;
        }

        left->next = list2;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = right;

        return list1; 
    }
};
