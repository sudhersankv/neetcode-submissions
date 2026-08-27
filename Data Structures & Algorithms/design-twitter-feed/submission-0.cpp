class Twitter {
public:


        std::vector<pair<int,int>> tweets; //index = post order, value is a vector of 
        std::unordered_map<int,std::unordered_set<int>> follows;
    Twitter() {

        // int userId;
        // int tweetId;

        // std::vector<pair<int,int>> tweets; //index = post order, value is a vector of 
        // std::unordered_map<int,std::unordered_set<int>> follows;
                
    }
    
    void postTweet(int userId, int tweetId) {

        // this->userId = userId;
        // this-> tweetId = tweetId;

        tweets.push_back({userId,tweetId});  
                
    }
    
    vector<int> getNewsFeed(int userId) {

        int count = 10;

        std::vector<int> feed;

        for(int i = tweets.size()-1; i>=0; i--)
        {
            if(count == 0)
            {break;}
            
            if(tweets[i].first == userId || follows[userId].find(tweets[i].first) != follows[userId].end())
            {
            feed.push_back(tweets[i].second);
            count--;
            }            
        }

        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {

        follows[followerId].insert(followeeId);

        
        
    }
    
    void unfollow(int followerId, int followeeId) {

        follows[followerId].erase(followeeId);
        
    }
};
