class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for(int i = 0; i < n; i++){
            friends.push_back(i + 1);
        }

        int id = 0;
        while(friends.size() > 1){
            id = (id + k - 1) % friends.size();
            friends.erase(friends.begin() + id);
        }

        return friends[0];
    }
};             