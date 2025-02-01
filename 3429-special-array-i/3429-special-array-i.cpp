//now using bits -> taking & with 1 , if even give 0, if odd give 1

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]&1) == (nums[i+1]&1)){
                return false;
            }
        }
        return true;
    }
};