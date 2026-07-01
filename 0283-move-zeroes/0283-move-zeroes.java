class Solution {
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        if(n<=1) return;
        int slow=0;
        for(int fast=0;fast<n;fast++){
            if(nums[fast]!=0){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        for(int i=slow;i<n;i++){
            nums[i]=0;
        }
    }
}