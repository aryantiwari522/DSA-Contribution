class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases: Negative numbers and numbers ending with 0 are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // If the length of the number is odd, we can ignore the middle digit
        // For example, in the number 12321, we can ignore the middle digit '3'
        return x == reversed || x == reversed / 10;
    }
};