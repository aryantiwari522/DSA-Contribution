class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> map;
        for(int i:arr)
        {
            map[i]++;
        }
        set<int> val;
        for(auto pair:map)
        {
            int freq=pair.second;
            if(val.find(freq)!=val.end())
            {
                return false;
            }
            else
            {
                val.insert(freq);
            }
        }
        return true;
    }
};