class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> temp = nums; 
        sort(temp.begin(), temp.end()); 

        for(int i = 0; i < temp.size(); i++){
            if(mpp.find(temp[i]) == mpp.end()){
                mpp[temp[i]] = i;
            }
        }

        vector<int> ret;
        for(int num : nums){
            ret.push_back(mpp[num]);
        }

        return ret;
    }
};