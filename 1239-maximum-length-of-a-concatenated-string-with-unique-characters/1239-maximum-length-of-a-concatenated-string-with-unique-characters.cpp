class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        backtrack(arr, 0, "", maxLen);
        return maxLen;
    }

private:
    void backtrack(const std::vector<std::string>& arr, int start,
                   const std::string& current, int& maxLen) {
        // Check if the current string has unique characters
        if (hasUniqueCharacters(current)) {
            maxLen = std::max(maxLen, static_cast<int>(current.length()));
        } else {
            return; // If not, no need to continue with this combination
        }

        // Try adding each string in the array to the current string
        for (int i = start; i < arr.size(); ++i) {
            backtrack(arr, i + 1, current + arr[i], maxLen);
        }
    }

    bool hasUniqueCharacters(const std::string& str) {
        std::vector<bool> seen(
            26, false); // Assuming only lowercase English letters
        for (char ch : str) {
            if (seen[ch - 'a']) {
                return false; // Duplicate character found
            }
            seen[ch - 'a'] = true;
        }
        return true; // All characters are unique
    }
};