class Solution {
public:
    int maxDepth(string s) {
        int length = 0;
        int maxLength = 0;
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
                maxLength = max(maxLength, (int)st.size());
            } 
            else if (c == ')') {
                if (!st.empty()) {
                    st.pop();
                } 
                else {
                    while (!st.empty()) st.pop();
                }
            }
        }

        return maxLength;
    }
};