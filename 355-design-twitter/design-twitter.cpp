class Twitter {
    private:
        // map to store tweets : int - userId, vector<pair<int, int>> - list of tweets, containing the timestamp and the tweetId
        unordered_map<int, vector<pair<int,int>>> tweets;
        // map to store the following list : int - userId, set - follower's/followee's userId set to make sure a user can't be followed multiple times.
        unordered_map<int, unordered_set<int>> following;
        int timestamp;
    public:
        Twitter() {
            // initialising the timestamp of the tweets as 0 to begin with
            timestamp = 0;
        }
        
        void postTweet(int userId, int tweetId) {
            tweets[userId].emplace_back(timestamp++, tweetId);
        }
        
        vector<int> getNewsFeed(int userId) {
            // priority queue to store the tweets in a descending order
            priority_queue<pair<int, int>> pq;

            // if user has tweets, add them to the priority queue
            if(tweets.count(userId)){
                // adding every tweet in that user's 'tweets' list
                for(auto &tweet : tweets[userId]){
                    pq.push(tweet);
                }
            }

            // add the followed user's tweets to the priority queue
            // if the 'userId' is following anyone (has values in the map)
            if(following.count(userId)){
                // for every follower or followee in the following list of the user
                for(int followeeId : following[userId]){
                    // if there are any tweets of the 'followeeId'
                    if(tweets.count(followeeId)){
                        // add every tweet to the feed
                        for(auto &tweet : tweets[followeeId]){
                            pq.push(tweet);
                        }
                    }

                }
            }

            // getting the most recent 10 tweets
            vector<int> newsFeed;
            int count = 0;
            while(!pq.empty() && count < 10){
                newsFeed.push_back(pq.top().second);
                pq.pop();
                count++;
            }

            return newsFeed;
        }
        
        void follow(int followerId, int followeeId) {
            // check if the follower and followee are not the same, to make sure a follow can't follow themselves.
            if(followerId != followeeId){
                // inserting the followee into the following list of the followerId
                following[followerId].insert(followeeId);
            }
        }
        
        void unfollow(int followerId, int followeeId) {
            // if the followerId follows anyone (the set has values)
            if(following.count(followerId)){
                following[followerId].erase(followeeId);
            }
        }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */