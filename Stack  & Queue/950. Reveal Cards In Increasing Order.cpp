class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {        
        sort(deck.begin(), deck.end(), greater<>());

        deque<int> dq;
        dq.push_front(deck[0]);
        vector<int> res;

        for(int i=1; i<deck.size(); i++)
        {
            int val = dq.back();
            dq.pop_back();
            dq.push_front(val);
            dq.push_front(deck[i]);
        }

        while(!dq.empty())
        {
            res.push_back(dq.front());
            dq.pop_front();
        }

        return res;
    }
};
