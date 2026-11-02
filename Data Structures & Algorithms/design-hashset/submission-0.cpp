    class MyHashSet {
        private:
            static const int size = 1009;
            vector<vector<int>> buckets;

            int hash(int key){
                return key % size;
            }


    public:
        MyHashSet() {
            buckets.resize(size);
        }
        
        void add(int key) {
            if (contains(key)) return;
            buckets[hash(key)].push_back(key);
        }
        
        void remove(int key) {
            vector<int>& b = buckets[hash(key)];
            for (int i = 0; i < b.size(); i++) {
                if (b[i] == key) {
                    b[i] = b.back();
                    b.pop_back();
                    return;
                }
            }
            
        }
        
        bool contains(int key) {
            for (int x : buckets[hash(key)]) {
                if (x == key) return true;
            }
            return false;
        }
    };

    /**
    * Your MyHashSet object will be instantiated and called as such:
    * MyHashSet* obj = new MyHashSet();
    * obj->add(key);
    * obj->remove(key);
    * bool param_3 = obj->contains(key);
    */