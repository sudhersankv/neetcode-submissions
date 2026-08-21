class LRUCache {
public:


    // store capacity, and create the containers

    int cap;
    std::unordered_map<int, std::list<pair<int,int>>::iterator> cache;
    std::list<pair<int,int>> lru;

    LRUCache(int capacity) {

        cap = capacity;
        
    }
    
    int get(int key) {

        //if not hit
        if(cache.find(key) == cache.end())
        {
            return -1;
        }
        else //if hit, return value from the key, retu
        {
            auto it = cache[key];

            lru.splice(lru.begin(), lru, it); //update mru
            return it->second;
        }
        
        
    }
    
    void put(int key, int value) {

        // check hit, if yes, update value, update mru
        //else, if cache full, pop lru, push key,value
        
        if(cache.find(key) != cache.end())
        {
            cache[key]->second = value;
            //make it mru
            lru.splice(lru.begin(), lru, cache[key]);
        }
        else
        {
            if(cache.size() == cap)
            {
                int remove = lru.back().first;
                lru.pop_back();
                cache.erase(remove);
                
            }

            lru.push_front({key,value});
            cache[key] = lru.begin();
        }
        
    }
};
