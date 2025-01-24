class LRUCache {
    private:
        int capacity; // Maximum capacity of the cache
        list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
        unordered_map<int, list<pair<int, int>>::iterator> map; // Hash map to store key and iterator to the list

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }

        int get(int key) {
            if (map.find(key) == map.end()) {
                return -1; // Key not found
            }

            // Move the accessed key-value pair to the front of the list
            auto it = map[key];
            cache.splice(cache.begin(), cache, it);
            return it->second;
        }

        void put(int key, int value) {
            if (map.find(key) != map.end()) {
                // Key already exists, update its value and move it to the front
                auto it = map[key];
                it->second = value;
                cache.splice(cache.begin(), cache, it);
            } else {
                // Key does not exist, add new key-value pair
                if (cache.size() == capacity) {
                    // Evict the least recently used key (at the back of the list)
                    int lruKey = cache.back().first;
                    cache.pop_back();
                    map.erase(lruKey);
                }

                // Insert the new key-value pair at the front
                cache.emplace_front(key, value);
                map[key] = cache.begin();
            }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */