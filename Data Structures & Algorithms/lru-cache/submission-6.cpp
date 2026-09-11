class LRUCache {
public:
    std::list<std::pair<int,int>> mru;
    std::unordered_map<int, list<std::pair<int,int>>::iterator> cache;
    int cap = 0;
    LRUCache(int capacity) {

        cap = capacity;

        
        
        //can maintain a doubly linked list to have the least recently used and most recently used.

        //it can be a list of hashmaps.


        //we can also maintain an hashmap which stores the top capacity recently used caches. it's value will have an iterator to access the data from list



        
    }
    
    int get(int key) {
        //access/read the key and give the value it has stored.

        //update the MRU


        // if cache hit
        if(cache.find(key) != cache.end())
        {   

            
            auto iterator = cache[key];
            mru.splice(mru.begin(), mru, iterator);
            return iterator->second;

        }
        return -1;
        
        
    }
    
    void put(int key, int value) {

        if(cache.find(key) != cache.end())
        {
            auto iterator = cache[key];
            iterator->second = value;

            mru.splice(mru.begin(), mru, iterator);

        }

        else
        {
            if(cache.size() == cap)
            {
                auto remove = mru.back();
                cache.erase(remove.first);
                mru.pop_back();

            }

            mru.push_front({key, value});
            cache[key] = mru.begin();
        }


        
    }
};
