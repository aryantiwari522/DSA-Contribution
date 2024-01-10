class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> indexMap;
    //     for(int num : nums)
    //     {
    //         indexMap[num]++;
    //     }
    //     for (const auto& pair : indexMap) {
    //     if (pair.second == 1) {
    //         return pair.first; // Found the key corresponding to the value
    //     }
    // }
    // return -1;


   // XOR logic
      int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
    }
};