class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> stk;
        int n = formula.size();

        for (int i = 0; i < n; i++) {
            char ch = formula[i];

            // Handling element names
            if (isupper(ch)) {
                string element = "";
                element += ch;
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    element += formula[j];
                    j++;
                }

                // Handling digits after element names
                string sdigit = "";
                while (j < n && isdigit(formula[j])) {
                    sdigit += formula[j];
                    j++;
                }
                if (sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                stk.push({element, digit});
                i = j - 1;
            }

            // Handle '('
            else if (ch == '(') {
                stk.push({"(", -1});
            }

            // Handle ')'
            else if (ch == ')') {
                int j = i + 1;
                string sdigit = "";
                while (j < n && isdigit(formula[j])) {
                    sdigit += formula[j];
                    j++;
                }
                if (sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                vector<pair<string, int>> temp;
                while (stk.top().first != "(") {
                    auto p = stk.top();
                    stk.pop();
                    temp.push_back({p.first, p.second * digit});
                }
                stk.pop(); // Pop the '('

                for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                    stk.push(*it);
                }
                i = j - 1;
            }
        }

        // Consolidate the counts
        map<string, int> mpp;
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            mpp[p.first] += p.second;
        }

        // Build the result string
        string ans = "";
        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            ans += it->first;
            if (it->second > 1) ans += to_string(it->second);
        }

        return ans;
    }
};