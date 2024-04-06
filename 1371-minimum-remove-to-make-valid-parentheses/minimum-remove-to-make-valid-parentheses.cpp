class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> openStack, closeStack;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == ')') {
                if (!openStack.empty()) {
                    openStack.pop();
                } else {
                    closeStack.push(i);
                }
            }
        }
        
        while (!openStack.empty()) {
            s.erase(openStack.top(), 1);
            openStack.pop();
        }
        
        while (!closeStack.empty()) {
            s.erase(closeStack.top(), 1);
            closeStack.pop();
        }
        
        return s;
    }
};