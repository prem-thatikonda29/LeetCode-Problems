class Solution {
public:
    int passThePillow(int n, int time) {
        int curr = 1;
        int dir = 1;
        while(curr <= n && time > 0){
            curr += dir;
            if(curr == n){
                dir = -1;
            }
            if(curr == 1){
                dir = 1;
            }
            time--;
        }

        return curr;
    }
};