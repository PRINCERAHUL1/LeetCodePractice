class Solution {
public:

    bool exist(string &s, string &pref)
    {
        if(pref.length() > s.length())
            return false;
        
        for(int i=0; i<pref.length(); i++)
        {
            if(pref[i] != s[i])
                return false;
        }

        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int res=0;

        for(auto s: words)
        {
            if(exist(s, pref))
                res++;
        }

        return res;
    }
};
