class LRUCache {
public:

    std::unordered_map<int, std::list<pair<int,int>>::iterator> cache;
    std::list<pair<int, int>> lru;
    int cap;


    LRUCache(int capacity) {

        cap = capacity;
        
    }
    
    int get(int key) {

        //else return -1
        if(cache.find(key) != cache.end())
        {
            auto iterator = cache[key];
            lru.splice(lru.begin(), lru, iterator);
            return iterator->second;

        }
        //if cache hits -> return value, update MRU
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        //if cache hit -> update value with new value

        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            it->second = value; // update value in the pair
            lru.splice(lru.begin(), lru, it);

        }
        //else
            //add key, value to cache
            //if cache capacity is full, evict least recently used and add new;
            //update most recently used

        else
        {
            if(cache.size() == cap)
            {
                

                auto remove = lru.back();
                cache.erase(remove.first);
                lru.pop_back();
            }

            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
        
    }
};
