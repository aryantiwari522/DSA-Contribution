class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length == 1) return 1;

        int slow=1;
        for(int fast=1;fast<nums.length;fast++){
            if(nums[fast]!=nums[slow-1]){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
}