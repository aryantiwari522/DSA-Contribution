class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        int lowDigits = to_string(low).size();
        int highDigits = to_string(high).size();
        
        for (int i = lowDigits; i <= highDigits; ++i) {
            for (int j = 0; j < 10 - i; ++j) {
                int num = stoi(digits.substr(j, i));
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};