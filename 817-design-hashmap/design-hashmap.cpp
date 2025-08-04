class MyHashMap {
public:
    map<int,int>mpp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mpp[key]=value;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            return mpp[key];
        }
        return -1;
    }
    
    void remove(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            mpp.erase(key);
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