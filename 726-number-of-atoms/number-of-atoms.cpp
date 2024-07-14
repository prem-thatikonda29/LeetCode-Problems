class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> stk;
        int n = formula.size();

        for (int i = 0; i < n; i++) {
            char ch = formula[i];

            // Handle '('
            if (ch == '(') {
                stk.push({"(", -1});
            }
            // Handle elements
            else if (isupper(ch)) {
                int j = i + 1; // Initialize j properly
                string element = "";
                element += ch;
                while (j < n && islower(formula[j])) {
                    element += formula[j];
                    j++;
                }

                string sdigit = "";
                while (j < n && isdigit(formula[j])) {
                    sdigit += formula[j];
                    j++;
                }

                if (sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                stk.push({element, digit});
                i = j - 1; // Update i properly
            }
            // Handle ')'
            else if (ch == ')') {
                string sdigit = "";
                int j = i + 1;
                while (j < n && isdigit(formula[j])) {
                    sdigit += formula[j];
                    j++;
                }

                if (sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                vector<pair<string, int>> temp;
                while (!stk.empty() && stk.top().first != "(") {
                    pair<string, int> p = stk.top();
                    stk.pop();
                    temp.push_back({p.first, p.second * digit});
                }
                stk.pop(); // Pop the '('

                for (auto it = temp.rbegin(); it != temp.rend(); it++) {
                    stk.push(*it);
                }
                i = j - 1; // Update i properly
            }
        }

        map<string, int> mp;
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            mp[p.first] += p.second;
        }

        string ans = "";
        for (auto it : mp) {
            ans += it.first;
            if (it.second > 1) ans += to_string(it.second); // Convert integer to string
        }

        return ans;
    }
};