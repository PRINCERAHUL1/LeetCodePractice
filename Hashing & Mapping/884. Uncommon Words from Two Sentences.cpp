class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        vector<string> res;
        string s = s1 + ' ' + s2;
        string temp = "";

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                m[temp]++;
                temp = "";
            }
            else
                temp += s[i];
        }

        m[temp]++;

        for(auto it: m)
        {
            if(it.second == 1)
                res.push_back(it.first);
        }

        return res;    
    }
};
