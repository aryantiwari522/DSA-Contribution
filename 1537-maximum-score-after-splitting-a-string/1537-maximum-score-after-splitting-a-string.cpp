class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
    int totalOnes = 0, leftZeros = 0, maxScore = 0;
    for (char c : s) {
        if (c == '1') totalOnes++;
    }

    int rightOnes = totalOnes; 
    for (int i = 0; i < n - 1; i++) {

        if (s[i] == '0') {
            leftZeros++;
        } else {
            rightOnes--;
        }
        maxScore = max(maxScore, leftZeros + rightOnes);
    }
    return maxScore;
    }
};