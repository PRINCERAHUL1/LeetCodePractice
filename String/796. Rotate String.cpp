class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() == 0)
            return false;
        
        for(int i=0; i<s.size(); i++)
        {
            char c = s[0];
            s.erase(0,1);
            s.push_back(c);

            if(s == goal)
                return true;
        }

        return false;
    }
};
