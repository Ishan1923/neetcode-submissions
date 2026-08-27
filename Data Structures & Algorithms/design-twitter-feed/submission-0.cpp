class Twitter {

    unordered_map<int, vector<pair<int, int>>> user_tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp;
    int feed_size;

public:
    Twitter() {
        timestamp = 0;
        feed_size = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {


        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;


        vector<int> feed;

        auto addLatest = [&](int uid){  
            const auto& tweets = user_tweets[uid];

            for(int i = 0; i < tweets.size(); i++){
                if(tweets.empty() == false)
                {
                    pq.push({tweets[i].first, tweets[i].second, uid, tweets.size() - 1});
                    if(pq.size() > feed_size) pq.pop();
                }
            }
        };

        addLatest(userId);

        for(auto user : following[userId]){
            addLatest(user);
        }

        while(!pq.empty()){
            auto [ts, tweetId, uid, idx] = pq.top();
            pq.pop();

            feed.push_back(tweetId);
        }

        reverse(feed.begin(), feed.end());

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
