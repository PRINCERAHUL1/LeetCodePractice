class Solution {

    struct TrieNode{
        TrieNode *child[26];
        string word;

        TrieNode(): word("")
        {
            for(int i=0; i<26; i++)
                child[i] = NULL;
        }
    };

public:

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &res)
    {
        char c = board[i][j];

        if(c == '#' || !p->child[c-'a'])
            return;
        
        p = p->child[c - 'a'];

        if(p->word.size() > 0)
        {
            res.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';

        if(i > 0)
            dfs(board, i-1, j, p, res);
        if(j > 0)
            dfs(board, i, j-1, p, res);
        if(i < board.size() - 1)
            dfs(board, i+1, j, p, res);
        if(j < board[0].size() - 1)
            dfs(board, i, j+1, p, res);
        
        board[i][j] = c;
    }

    TrieNode* buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();

        for(int i=0; i<words.size(); i++)
        {
            string word = words[i];
            TrieNode *cur = root;

            for(int j=0; j<word.length(); j++)
            {
                char c = word[j] - 'a';

                if(cur->child[c] == NULL)
                    cur->child[c] = new TrieNode();
                
                cur = cur->child[c];
            }

            cur->word = word;
        }

        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> res;

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                dfs(board, i, j, root, res);
            }
        }

        return res;
    }
};
