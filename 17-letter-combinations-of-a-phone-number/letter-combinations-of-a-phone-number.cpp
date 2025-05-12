class Solution {
public:
    vector<string> res;
    vector<string> codes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dialpad(string str, string ans){
        if(str.length() == 0){
            res.push_back(ans);
            return;
        }

        char ch = str[0];
        string roq = str.substr(1);

        int idx = ch - '0';
        for(int i = 0; i < codes[idx].length(); i++){
            char code = codes[idx][i];
            dialpad(roq, ans + code);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }

        dialpad(digits, "");
        return res;
    }
};