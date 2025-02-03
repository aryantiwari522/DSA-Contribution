class Solution {
public:
    int findMin(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                result=nums[i];
            }
        }
        return result;
    }
};