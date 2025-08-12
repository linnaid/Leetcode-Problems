class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        for(auto c : s) {
            if(c == ')') {
                st.pop();
            }
            if(!st.empty()) {
                ans.push_back(c);
            }
            if(c == '(') {
                st.push(c);
            }
        }
        return ans;
    }
};