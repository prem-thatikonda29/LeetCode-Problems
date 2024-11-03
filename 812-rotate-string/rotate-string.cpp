class Solution {
public:
    bool isPossible(string s, string goal, int n, int shift) {
        for (int i = 0; i < n; i++) {
            if (s[(i + shift) % n] != goal[i]) {
                return false;
            }
        }
        return true;
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (isPossible(s, goal, n, i)) return true;
        }
        
        return false;
    }
};
