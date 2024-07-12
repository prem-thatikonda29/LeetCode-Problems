class Solution {
public:
    int maximumGain(string s, int x, int y) {
    int score = 0;
    
    // Determine the order of removal based on the points
    if (x > y) {
        // Remove "ab" first
        stack<char> stk;
        string remaining;
        for (char c : s) {
            if (!stk.empty() && stk.top() == 'a' && c == 'b') {
                score += x;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        // Remove "ba" next
        for (char c : remaining) {
            if (!stk.empty() && stk.top() == 'b' && c == 'a') {
                score += y;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
    } else {
        // Remove "ba" first
        stack<char> stk;
        string remaining;
        for (char c : s) {
            if (!stk.empty() && stk.top() == 'b' && c == 'a') {
                score += y;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        // Remove "ab" next
        for (char c : remaining) {
            if (!stk.empty() && stk.top() == 'a' && c == 'b') {
                score += x;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
    }
    
    return score;
}
};