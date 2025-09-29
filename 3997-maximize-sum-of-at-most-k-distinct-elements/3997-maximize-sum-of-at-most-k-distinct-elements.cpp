class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> s;
        sort(nums.begin(),nums.end(),greater<int>());
        s.push_back(nums[0]);
        int i=1, count=1;
        while(count<k){
            if(i==nums.size()) break;
            if(nums[i]!=nums[i-1]){
                s.push_back(nums[i]);
                count++;
            }
            i++;
        }
        return s;
    }
};