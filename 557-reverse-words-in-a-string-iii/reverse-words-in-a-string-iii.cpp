class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                res += s[i];
            }
            else{
                reverse(res.begin(), res.end());
                ans = ans + (res + " ");
                res = "";
            }
        }

        reverse(res.begin(), res.end());
        ans += res;

        return ans;
    }
};