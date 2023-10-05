class MyHashMap {
    vector<pair<int, int>> map;

public:
    MyHashMap() {

    }

    void put(int key, int value) {
        for(auto& pair : map)
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        map.push_back(make_pair(key, value));
    }

    int get(int key) {
        for(auto pair : map)
            if(pair.first == key)
                return pair.second;
        return -1;
    }

    void remove(int key) {
        for(auto i = map.begin(); i != map.end(); i++) {
            if(i->first == key) {
                map.erase(i);
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