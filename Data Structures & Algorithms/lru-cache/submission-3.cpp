class LRUCache {
public:


    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache;
    std::list<std::pair<int,int>> lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;

        
    }
    
    int get(int key) {

        
        
        
        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            lru.splice(lru.begin(), lru, it);
            return it->second;
            
        }
        else
        {
            return -1;
        }

        

        // if hit, return value, else return -1
        //update, most recenetly used
        
    }
    
    void put(int key, int value) {


        //if hit, update value, else create key value pair to chache.
        if(cache.find(key) != cache.end())
        {
            auto it = cache[key];
            it->second = value;
            lru.splice(lru.begin(), lru, it);
        }
        else
        {
            if(cache.size() == cap)
            {
                cache.erase((lru.back().first));
                lru.pop_back();
            }
            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
        //update MRU.

        //if cache at cap, remove LRU and add new pair

        
    }
};
