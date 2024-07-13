class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids;

        for(int i = 0; i < n; i++){
            ids.push_back(i);
        }

        auto compare = [&](int id1, int id2){
            return positions[id1] <= positions[id2];
        };

        sort(ids.begin(), ids.end(), compare);
        stack<int> stk;
        for(auto id : ids){
            if(directions[id] == 'R'){
                stk.push(id);
            }
            else{
                while(!stk.empty() && healths[id] > 0){
                    if(healths[id] > healths[stk.top()]){
                        healths[id]--;
                        healths[stk.top()] = 0;
                        stk.pop();
                    }
                    else if(healths[id] < healths[stk.top()]){
                        healths[stk.top()]--;
                        healths[id] = 0;
                    }
                    else{
                        healths[id] = 0;
                        healths[stk.top()] = 0;
                        stk.pop();
                    }
                }
            }
        }

        vector<int> result;
        for(int health : healths){
            if(health != 0){
                result.push_back(health);
            }
        }
        return result;
    }
};