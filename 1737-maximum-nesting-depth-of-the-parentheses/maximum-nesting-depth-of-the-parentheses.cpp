class Solution {
public:
    int maxDepth(string s) {
        if(s == "") return 0;
        int length = 0;
        int maxLength = 0;
        for (char c : s) {
            if (c == '(') {
                length++;
                maxLength = max(length, maxLength);
            } 
            else if (c == ')') {
                length--;
            }
            else{
                continue;
            }
        }

        return maxLength;
    }
};