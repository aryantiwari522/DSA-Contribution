class NumberContainers {
public:
    unordered_map<int,int> idxTonum;
    unordered_map<int,set<int>> numToidx;
    NumberContainers() {
        //
    }
    
    void change(int index, int number) {
        if(idxTonum.count(index))
        {
            int prevNum=idxTonum[index];
            numToidx[prevNum].erase(index);
            if(numToidx[prevNum].empty())
            {
                numToidx.erase(prevNum);
            }
        }
        idxTonum[index]=number;
        numToidx[number].insert(index);
    }
    
    int find(int number) {
        if(numToidx.find(number)!=numToidx.end())
        {
            return *numToidx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */