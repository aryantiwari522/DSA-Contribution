class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int n= nums.length;
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target =-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum==target){
                   result.add(List.of(nums[i], nums[left], nums[right]));
                   while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                    } 
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }

            }
            
    return result;
        }
    }