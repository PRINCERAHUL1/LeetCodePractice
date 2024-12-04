class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* ptr = head;
        ListNode* temp = head;
        int count = 0;
        
        while(ptr)
        {
            count++;
            ptr = ptr->next;
        }        

        ptr = head;

        if(count < k)
        {
            while(ptr)
            {
                res.push_back(ptr);
                temp = ptr;
                ptr = ptr->next;
                temp->next = NULL;
            }

            for(int i=1; i<=(k-count); i++)
                res.push_back(NULL);
        }
        else
        {
            int div = count/k;
            int rem = count%k;

            while(ptr)
            {
                if(rem != 0)
                {
                    res.push_back(ptr);

                    for(int i=1; i<=div; i++)
                        ptr = ptr->next;

                    temp = ptr;
                    ptr = ptr->next;
                    temp->next = NULL;
                    rem--;
                }
                else
                {
                    res.push_back(ptr);
                    for(int i=1; i<div; i++)
                        ptr = ptr->next;

                    temp = ptr;
                    ptr = ptr->next;
                    temp->next = NULL;
                }
            }
        }

        return res;
    }
};
