class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int n:nums)
        {
            mp[n]++;
        }
        priority_queue<pair<int,int>> pQ;
        for(const auto& pair:mp)
        {
            pQ.push({pair.second,pair.first});
        }
        while(!pQ.empty() && k-- >0)
        {
            result.push_back(pQ.top().second);
            pQ.pop();

        }
        return result;
    }
};