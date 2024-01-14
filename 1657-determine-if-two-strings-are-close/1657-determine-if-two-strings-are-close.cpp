class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        unordered_map<char, int> freq1, freq2;
        unordered_set<char> chars1, chars2;

        // Count frequencies of characters in word1
        for (char c : word1) {
            freq1[c]++;
            chars1.insert(c);
        }

        // Count frequencies of characters in word2
        for (char c : word2) {
            freq2[c]++;
            chars2.insert(c);
        }

        // Check if the sets of characters are the same
        if (chars1 != chars2) {
            return false;
        }

        // Check if the sets of frequencies are the same
        multiset<int> freqSet1, freqSet2;
        for (auto& entry : freq1) {
            freqSet1.insert(entry.second);
        }
        for (auto& entry : freq2) {
            freqSet2.insert(entry.second);
        }

        if(freqSet2!=freqSet1)
        {
            return false;
        }
        return true;
     
    }
};