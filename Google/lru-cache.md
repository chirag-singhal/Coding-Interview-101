## [LRU Cache](https://leetcode.com/problems/lru-cache/)

### Problem Link - https://leetcode.com/problems/lru-cache/

---

### Solution

```cpp

    class LRUCache {
    public:
        std::unordered_map<int, std::list<std::pair<int,int>>::const_iterator> map;
        std::list<std::pair<int, int>> cache;
        int size;
        
        LRUCache(int capacity) {
            size = capacity;
        }
        
        int get(int key) {
            auto itr = map.find(key);
            if(itr != map.end()) {
                auto i2 = *map[key];
                int val = i2.second; 
                cache.erase(map[key]);
                cache.push_front(std::make_pair(key, val));
                map[key] = cache.cbegin();
                return val;
            }
            return -1;
        }
        
        void put(int key, int value) {
            auto itr = map.find(key);
            if(itr != map.end()) {
                cache.erase(map[key]);
                cache.push_front(std::make_pair(key, value));
                map[key] = cache.cbegin();
            }
            else {
                if(cache.size() == size) {
                    int key1 = cache.back().first;
                    cache.pop_back();
                    map.erase(map.find(key1));
                    cache.push_front(std::make_pair(key, value));
                    map[key] = cache.cbegin();
                }
                else {
                    cache.push_front(std::make_pair(key, value));
                    map[key] = cache.cbegin();
                }
            }
        }
    };

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */

```