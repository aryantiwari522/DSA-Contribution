class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        if(n<=1) return;
        int slow=0;
        for(int fast=0;fast<n;fast++){
            if(nums[fast]!=0){
               if (nums[fast] != 0) {
                
                if (fast != slow) {
                    int temp = nums[fast];
                    nums[fast] = nums[slow];
                    nums[slow] = temp; 
                }
                slow++;
            }
            }
        }
    }
}