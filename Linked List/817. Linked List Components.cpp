class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        if(head == NULL || nums.size() == 0)
            return 0;
        
        set<int> s;
        int res=0;
        bool connect = false;

        for(auto i: nums)
            s.insert(i);
        
        while(head)
        {
            int val = head->val;

            if(s.count(val) && connect == false)
            {
                connect = true;
                res++;
            }
            else if(s.count(val)==0 && connect == true)
                connect = false;
            
            head = head->next;
        }

        return res;
    }
};
