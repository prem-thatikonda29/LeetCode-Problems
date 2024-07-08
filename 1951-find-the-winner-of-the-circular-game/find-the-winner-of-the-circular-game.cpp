class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for(int i = 0; i < n; i++){
            friends.push_back(i + 1);
        }

        int index = 0;
        while(friends.size() > 1){
            index = (index + k - 1) % friends.size();
            friends.erase(friends.begin() + index);
        }

        return friends[0];
    }
};