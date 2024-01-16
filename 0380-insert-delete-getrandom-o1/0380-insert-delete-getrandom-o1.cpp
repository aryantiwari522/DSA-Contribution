class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valueToIndex.find(val) != valueToIndex.end()) {
            return false; // Value already exists in the set
        }

        values.insert(val);
        valueToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (valueToIndex.find(val) == valueToIndex.end()) {
            return false; // Value not found in the set
        }

        // Get the iterator to the value in the set
        auto it = values.find(val);

        // Erase the value from the set
        values.erase(it);

        // Erase the value from the index map
        valueToIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        // Use rand() to generate a random index within the range of the set
        int randomIndex = rand() % values.size();

        // Advance the iterator to the random index
        auto it = std::next(values.begin(), randomIndex);

        return *it;
    }
    private:
    std::set<int> values;
    std::unordered_map<int, int> valueToIndex;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */