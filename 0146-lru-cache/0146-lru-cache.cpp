class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> vals;
    list<int> last_access;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (vals.count(key)) {
            last_access.erase(vals[key].second);
            last_access.push_back(key);
            vals[key].second = --last_access.end();
            return vals[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (vals.count(key)) {
            last_access.erase(vals[key].second);
        } else {
            if (vals.size() >= this->capacity) {
                int lru = last_access.front();
                last_access.pop_front();
                vals.erase(lru);
            }
        }
        last_access.push_back(key);
        vals[key] = {value, --last_access.end()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */