class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) {
            return ""; // Return an empty string if the array is empty.
        }

        // Sort the array of strings.
        sort(strs.begin(), strs.end());

        // Compare the first and last strings in the sorted array.
        string first = strs[0];
        string last = strs[strs.size() - 1];

        // Find the common prefix between the first and last strings.
        int commonLength = 0;
        for (int i = 0; i < first.length(); i++) {
            if (first[i] == last[i]) {
                commonLength++;
            } else {
                break; // Stop if a mismatch is found.
            }
        }

        return first.substr(0, commonLength);
    }
};