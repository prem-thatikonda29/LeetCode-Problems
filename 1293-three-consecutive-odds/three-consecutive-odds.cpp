class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddOcc = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 != 0){
                oddOcc++;
                if(oddOcc == 3){
                    return true;
                }
            }
            else{
                oddOcc = 0;
            }
        }

        return false;
    }
};