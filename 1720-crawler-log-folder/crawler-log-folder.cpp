class Solution {
public:
    int minOperations(vector<string>& logs) {
        int moves = 1;
        for(const auto& log : logs){
            if((log == "../" && moves == 1) || log == "./"){
                continue;
            }
            if(log == "../" and moves > 1){
                moves--;
            }
            else{
                moves++;
            }
        }

        return moves - 1;
    }
};