class Solution {
public:
    bool checkPal(string curr){
        if(curr.empty()) return false;

        if(curr.length() == 1) return true;

        int i = 0; 
        int j = curr.length() - 1;
        while(i <= j){
            if(curr[i] == curr[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }

        return true;
    }

    void solve(string str, vector<vector<string>>& ans, vector<string>& inn){
        if(str.empty()){
            ans.push_back(inn);
            return;
        }

        for(int i = 1; i <= str.length(); i++){
            string partition = str.substr(0, i);
            if(checkPal(partition)){
                inn.push_back(partition);
                solve(str.substr(i), ans, inn);
                inn.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> inner;

        if(s.empty()) return {{}};

        solve(s, ans, inner);
        return ans;
    }
};