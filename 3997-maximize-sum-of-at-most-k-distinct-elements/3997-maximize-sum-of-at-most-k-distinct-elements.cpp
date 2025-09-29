class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        // store all unique numbers in descending order
        set<int, greater<int>> st(nums.begin(), nums.end());

        vector<int> ans;
        int count = 0;
        for (int x : st) {
            if (count == k) break;
            ans.push_back(x);
            count++;
        }
        return ans;
    }
};
