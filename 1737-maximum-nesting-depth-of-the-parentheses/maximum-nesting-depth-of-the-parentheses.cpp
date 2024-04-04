class Solution {
public:
    int maxDepth(string s) {
        if(s == "") return 0;
        int length = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                length++;
                maxLength = max(length, maxLength);
            } 
            else if (s[i] == ')') {
                length--;
            }
            else{
                continue;
            }
        }

        return maxLength;
    }
};