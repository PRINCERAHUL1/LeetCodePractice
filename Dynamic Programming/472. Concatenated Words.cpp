class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;

        for (const string& word : words)
        {
            int l = word.length();
            vector<bool> dp(l + 1);
            dp[0] = true;

            for (int i=1; i<=l; i++)
            {
                for (int j= (i == l ? 1 : 0); !dp[i] && j < i; j++)
                    dp[i] = dp[j] && dict.count(word.substr(j, i - j));
            }

            if (dp[l]) 
                res.push_back(word);
        }
        return res;
    }
};
