class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        int mod = 1e9 + 7;
        long res = 0;

        for(int x: arr)
            m[x]++;

        for(auto it1: m)
        {
            for(auto it2: m)
            {
                int i = it1.first;
                int j = it2.first;
                int k = target - i - j;

                if(!m.count(k))
                    continue;
                
                if(i==j && j==k)
                    res += (m[i] * (m[i] - 1) * (m[i] - 2)) / 6;
                else if(i==j && j!=k)
                    res += ((m[i] * (m[i] - 1)) / 2) * m[k];
                else if(i<j && j<k)
                    res += m[i] * m[j] * m[k];
            }
        }

        return res%mod;
    }
};
