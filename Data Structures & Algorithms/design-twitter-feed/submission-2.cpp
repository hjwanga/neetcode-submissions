class Twitter {
    // [user] : {<time, tweet>}
    deque<pair<int,int>> user2tweets[501];
    unordered_set<int> user2follows[501];
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user2tweets[userId].push_front(make_pair(time, tweetId));
        if (user2tweets[userId].size() > 10) {
            user2tweets[userId].pop_back();
        }
        ++time;
    }
    
    // 順序: time 大到小
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        result.reserve(10);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int follow : user2follows[userId]) {
            for (const auto& [time, tweetId] : user2tweets[follow]) {
                pq.emplace(time, tweetId);
                if ((int)pq.size() > 10) {
                    pq.pop();
                }
            }
        }
        for (const auto& [t, tweetId] : user2tweets[userId]) {
            pq.emplace(t, tweetId);
            if ((int)pq.size() > 10) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            auto [t, tweetId] = pq.top();
            pq.pop();
            result.push_back(tweetId);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    // follow(1, 2) := 1 follow 2
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        user2follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        user2follows[followerId].erase(followeeId);
    }
};
