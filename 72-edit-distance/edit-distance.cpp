
class Solution {
public:
    int solve(string s1, string s2, vector<vector<int>>& arr, int size1, int size2){
        if(size1 == 0){
            return arr[size1][size2] = size2;  // inserting all remaining characters of s2
        }

        if(size2 == 0){
            return arr[size1][size2] = size1;  // deleting all remaining characters of s1
        }

        if(arr[size1][size2] != -1){
            return arr[size1][size2];
        }

        if(s1[size1 - 1] == s2[size2 - 1]){
            return arr[size1][size2] = solve(s1, s2, arr, size1 - 1, size2 - 1);
        }

        int insert = solve(s1, s2, arr, size1, size2 - 1);
        int del = solve(s1, s2, arr, size1 - 1, size2);
        int replace = solve(s1, s2, arr, size1 - 1, size2 - 1);

        arr[size1][size2] = min({insert, del, replace}) + 1;
        return arr[size1][size2];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(word1, word2, dp, n, m);
    }
};