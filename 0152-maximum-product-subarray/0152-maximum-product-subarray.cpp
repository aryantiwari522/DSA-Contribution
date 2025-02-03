class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int longest=1; 
        int minProduct=nums[0];
        int maxProduct=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int n=nums[i];
           if (n < 0) {
                swap(minProduct, maxProduct);
            }
            minProduct = min(n, minProduct * n);
            maxProduct = max(n, maxProduct * n);
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};