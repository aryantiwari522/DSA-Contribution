class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freqMap;

        // Step 1: count frequencies of each character
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: group characters by frequency
        unordered_map<int, vector<char>> groups;
        for (auto &p : freqMap) {
            groups[p.second].push_back(p.first);
        }

        // Step 3: find the group with max size, break ties with higher frequency
        int bestSize = 0;
        int bestFreq = 0;
        vector<char> bestGroup;

        for (auto &g : groups) {
            int freq = g.first;
            int size = g.second.size();

            if (size > bestSize || (size == bestSize && freq > bestFreq)) {
                bestSize = size;
                bestFreq = freq;
                bestGroup = g.second;
            }
        }

        // Step 4: convert result to string
        string result;
        for (char c : bestGroup) result.push_back(c);

        return result;
    }
};
