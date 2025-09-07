class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
if (n == 0) {
            return true;
        }

        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left neighbor is empty or out of bounds.
                bool is_left_empty = (i == 0 || flowerbed[i - 1] == 0);
                
                // Check if the right neighbor is empty or out of bounds.
                bool is_right_empty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                
                // If both neighbors are empty, plant a flower.
                if (is_left_empty && is_right_empty) {
                    flowerbed[i] = 1;
                    n--;
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};