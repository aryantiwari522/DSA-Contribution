class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr1(arr.size(),0);
        vector<int> result(arr.size(),0);
        int idx=0;
        for(int n:arr)
        {
            arr1[idx++]=n;
        }
        idx=0;
        sort(arr1.begin(),arr1.end());
        unordered_map<int, int> mp;
        int rank = 1;
        
        for (int n : arr1) {
            // Assign rank only if the element is not already in the map
            if (mp.find(n) == mp.end()) {
                mp[n] = rank++;
            }
        };
        for(int n:arr)
        {
            result[idx++]=mp[n];
        }
    return result;
    }
};