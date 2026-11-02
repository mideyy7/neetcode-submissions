class MyHashMap {
private:
    static const int size = 1009;
    int hash(int key) {
        return key % size;
    }
    vector<vector<pair<int,int>>> bucket;
public:
    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int h = hash(key);
        if (get(key) == -1) {
            bucket[h].push_back({key, value});
        } else {
            remove(key);
            put(key, value);
        }
    }
    
    int get(int key) {
        vector<pair<int,int>>& v = bucket[hash(key)];
        for (auto [k, v] : v) {
            if (k == key) return v;
        }
        return -1;
    }
    
    void remove(int key) {
        vector<pair<int,int>>& v = bucket[hash(key)];
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first == key) {
                v[i] = v.back();
                v.pop_back();
                return;
            }
        }

        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */