class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length;
      
        // If array has less than 2 elements, no gap exists
        if (n < 2) {
            return 0;
        }
      
        // Initialize constants and find min/max values in the array
        final int INFINITY = 0x3f3f3f3f;
        int minValue = INFINITY;
        int maxValue = -INFINITY;
      
        for (int num : nums) {
            minValue = Math.min(minValue, num);
            maxValue = Math.max(maxValue, num);
        }
      
        // Calculate bucket size using pigeonhole principle
        // The minimum possible maximum gap is (max - min) / (n - 1)
        int bucketSize = Math.max(1, (maxValue - minValue) / (n - 1));
        int bucketCount = (maxValue - minValue) / bucketSize + 1;
      
        // Initialize buckets - each bucket stores [min, max] values
        int[][] buckets = new int[bucketCount][2];
        for (int[] bucket : buckets) {
            bucket[0] = INFINITY;    // minimum value in bucket
            bucket[1] = -INFINITY;   // maximum value in bucket
        }
      
        // Distribute numbers into buckets based on their values
        for (int num : nums) {
            int bucketIndex = (num - minValue) / bucketSize;
            buckets[bucketIndex][0] = Math.min(buckets[bucketIndex][0], num);
            buckets[bucketIndex][1] = Math.max(buckets[bucketIndex][1], num);
        }
      
        // Find maximum gap by comparing adjacent non-empty buckets
        int previousMax = INFINITY;
        int maxGap = 0;
      
        for (int[] bucket : buckets) {
            // Skip empty buckets (where min > max after initialization)
            if (bucket[0] > bucket[1]) {
                continue;
            }
          
            // Calculate gap between current bucket's min and previous bucket's max
            maxGap = Math.max(maxGap, bucket[0] - previousMax);
            previousMax = bucket[1];
        }
      
        return maxGap;
    }
}