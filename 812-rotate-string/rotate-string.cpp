class Solution {
public:
    bool rotateString(string s, string goal) {
        string newStr = "";
        if(s == goal) return true;
        if(s.length() != goal.length()) return false;

        for(int i = 0; i < s.length(); i++){
            newStr = s.substr(i) + s.substr(0, i);
            if(newStr == goal) return true;
        }

        return false;
    }
};