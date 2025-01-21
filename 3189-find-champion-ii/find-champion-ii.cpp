class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n, 0);

        for(const auto& team : edges){
            inDegrees[team[1]]++;
        }

        int champion = -1;
        for(int i = 0; i < n; i++){
            if(inDegrees[i] == 0){
                if(champion != -1){
                    return -1;
                }
                else{
                    champion = i;
                }
            }
        }

        return champion;
    }
};