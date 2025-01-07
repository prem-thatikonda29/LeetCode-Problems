class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;

        // Sort words by length in ascending order
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // Check substrings only against longer words
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // Found a match, move to the next word
                }
            }
        }

        return result;
    }
};