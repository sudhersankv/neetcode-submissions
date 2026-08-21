class LRUCache {
public:
    std::list<std::pair<int,int>> lru;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache;
    int cap;

    LRUCache(int capacity) {
        //store max cap of cache
        // init list and unordered map empty

        cap = capacity;


        
    }
    
    int get(int key) {


        //check if key exists
        
        //miss - return -1
        if(cache.find(key)==cache.end())
        {
            return -1;
        }
        //hit
        else
        {
            auto it = cache[key];
            lru.splice(lru.begin(), lru, it); // becomes MRU
            return it->second;
        }
    }
    
    void put(int key, int value) {

        //hit
        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            it->second = value;
            lru.splice(lru.begin(), lru, it); //becomes MRU
        }
        else
        {   //if cap full, evict Least recent
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
