class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
         int xor1 = 0, xor2 = 0;

        for (int num : nums1) xor1 ^= num;
        for (int num : nums2) xor2 ^= num;

        int result = 0;
        if (nums2.size() % 2 != 0) result ^= xor1;
        if (nums1.size() % 2 != 0) result ^= xor2;

        return result;
    }
};