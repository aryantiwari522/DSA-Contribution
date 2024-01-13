#include <unordered_map>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int t : nums) {
            map[t]++;
        }
       int ans=0;
        for (const auto& pair : map) {
            int count = pair.second;
            if(count==1)
            {
                return -1;
            }
            if(count%3==0)
            {
                ans+=count/3;
            }
            else
            {
                ans+=count/3+1;
            }
        }
        return ans;

        // unordered_map<int, int> freq; // To store the frequency of each element
        // priority_queue<int>
        //     maxHeap; // Max heap to get the element with the maximum frequency

        // for (int num : nums) {
        //     freq[num]++;
        // }

        // int operations = 0;

        // for (auto& entry : freq) {
        //     maxHeap.push(entry.second);
        // }

        // while (!maxHeap.empty()) {
        //     int count = maxHeap.top();
        //     maxHeap.pop();

        //     if (count == 1) {
        //         return -1; // It is impossible to empty the array
        //     }

        //     if (count % 3 == 0) {
        //         operations += count / 3; // Three elements with equal values
        //     } else {
        //         operations +=
        //             count / 3 +
        //             1; // Some elements are left, use an extra operation
        //     }
        // }

        // return operations;
    }
};
