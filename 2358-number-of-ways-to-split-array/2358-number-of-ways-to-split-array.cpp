class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> prefixsum(nums.size()+1,0);
        vector<long> suffixsum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            suffixsum[i]=suffixsum[i+1]+nums[i];
        }
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(prefixsum[i]>=suffixsum[i])
            {
                count++;
            }
        }
        return count;
    }
};