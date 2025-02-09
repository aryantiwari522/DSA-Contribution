class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-i;
        }
        mp[nums[0]]=1;
        for(int j=1;j<nums.size();j++)
        {
            int countOfnumsj=mp[nums[j]];
            int totalNumberBeforej=j;
            int badPair=totalNumberBeforej-countOfnumsj;
            ans+=badPair;
            mp[nums[j]]++;
        }
        return ans;
    }
};