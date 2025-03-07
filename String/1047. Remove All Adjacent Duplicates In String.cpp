class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for(char c: s)
        {
            if(res.size() && res.back() == c)
                res.pop_back();
            else
                res.push_back(c);
        }

        return res;
    }
};


//class Solution {
//public:
//    string removeDuplicates(string s) {
//        string res;
//        stack<char> st;
//        
//        for(int i=0; i<s.size(); i++)
//        {
//            if(st.size() == 0)
//                st.push(s[i]);
//            else if(s[i] == st.top())
//                st.pop();
//            else
//                st.push(s[i]);
//        }
//
//        while(st.size() != 0)
//        {
//            res = st.top() + res;
//            st.pop();
//        }
//
//        return res;
//    }
//};
