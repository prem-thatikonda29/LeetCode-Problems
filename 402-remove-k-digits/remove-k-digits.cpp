class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";

        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        result.resize(result.length() - k);

        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};