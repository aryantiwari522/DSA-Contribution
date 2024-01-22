class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> input;
        vector<int> result;
        int duplicate=-1;
        // for(int i:nums)
        // {
        //     if(input.find(i)!= input.end())
        //     {
        //         duplicate=i;
        //     }
        //     input.insert(i);
        // }
        // for (int i = 1; i <= nums.size(); ++i) {
        //     if (input.find(i) == input.end()) {
        //         result.push_back(duplicate);
        //         result.push_back(i);
        //         break;
        //     }
        // }

        for (int i = 0; i < nums.size(); ++i) {
            // Swap the current element to its correct position
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(nums[i]); // Duplicate
                result.push_back(i + 1);    // Missing
                break;
            }
        }
        return result;
    }
};