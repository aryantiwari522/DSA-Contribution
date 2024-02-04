class Solution {
public:
    string minWindow(string s, string t) {
          unordered_map<char, int> targetFreq;
    for (char c : t) {
        targetFreq[c]++;
    }

    int requiredChars = targetFreq.size();
    int formed = 0;
    unordered_map<char, int> windowFreq;
    int left = 0, right = 0;
    int minWindowLength = INT_MAX, minWindowStart = -1;

    while (right < s.length()) {
        char currentChar = s[right];
        windowFreq[currentChar]++;

        if (targetFreq.find(currentChar) != targetFreq.end() && windowFreq[currentChar] == targetFreq[currentChar]) {
            formed++;
        }

        while (left <= right && formed == requiredChars) {
            if (right - left + 1 < minWindowLength) {
                minWindowLength = right - left + 1;
                minWindowStart = left;
            }

            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (targetFreq.find(leftChar) != targetFreq.end() && windowFreq[leftChar] < targetFreq[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if (minWindowStart == -1) {
        return "";
    }

    return s.substr(minWindowStart, minWindowLength);
    }
};