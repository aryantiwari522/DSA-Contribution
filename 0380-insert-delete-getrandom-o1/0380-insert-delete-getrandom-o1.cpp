class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexMap.find(val)!=indexMap.end()) return false;

        value.push_back(val);
        indexMap[val]=value.size()-1;
        return true;
    }
    
    bool remove(int val) {
       if(indexMap.find(val)==indexMap.end()){
           return false;
           }

       int last=   value.back();
        indexMap[last]=indexMap[val];
       value[indexMap[last]]=last;
       value.pop_back();
       indexMap.erase(val);
       return true;
    }
    
    int getRandom() {
        // Use rand() to generate a random index within the range of the set
        int randomIndex = rand() % value.size();

        return value[randomIndex];
    }
    private:
    vector<int> value;
    unordered_map<int, int> indexMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */