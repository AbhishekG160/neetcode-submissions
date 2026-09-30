class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> following; // A -> B,C,D --> A follows B,C,D 
    unordered_map<int, vector<pair<int,int>>> posts;  // ID 1 -> {timestamp , tweet}
public:
    Twitter():time(0) {}
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 10 most recent posts from itself and followee
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        unordered_set<int> accounts = following[userId];
        accounts.insert(userId);

        for(auto& acc:accounts)
            if(posts.find(acc) != posts.end()){ // posts available from this account or not 
                int count = 0;
                auto& post = posts[acc];
                for(auto iter = post.rbegin(); iter != post.rend() && count<10; count++, iter++){
                    minh.push(*iter);
                    if(minh.size() > 10)
                        minh.pop();
                }
            }

        vector<int> result;
        while(!minh.empty()){
            result.push_back(minh.top().second);
            minh.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};
