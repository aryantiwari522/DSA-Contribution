class Solution {
    public int compress(char[] chars) {
        int slow = 0;
        int fast = 0;

        while (fast < chars.length) {

            char currentChar = chars[fast];
            int count = 0;

            // Count the current group
            while (fast < chars.length && chars[fast] == currentChar) {
                fast++;
                count++;
            }

            // Write the character
            chars[slow++] = currentChar;

            // Write the count if greater than 1
            if (count > 1) {
                String countStr = String.valueOf(count);

                for (char c : countStr.toCharArray()) {
                    chars[slow++] = c;
                }
            }
        }

        return slow;
        
    }
}