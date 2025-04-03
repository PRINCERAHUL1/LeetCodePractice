class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(auto it: arr)
            m[it]++;
        
        multimap<int, int, greater<int>> mm;
        for(auto it: m)
            mm.insert({it.second, it.first});
        
        int n = arr.size();
        int temp = n;
        int count = 0;
        for(auto it=mm.begin(); it!=mm.end(); it++)
        {
            temp -= it->first;
            count++;

            if(temp <= n/2)
                return count;
        }

        return count;
    }
};
