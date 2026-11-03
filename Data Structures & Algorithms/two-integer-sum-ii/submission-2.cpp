class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            if (numbers[lo] + numbers[hi] > target) {
                hi -= 1;
            } else if (numbers[lo] + numbers[hi] < target) {
                lo += 1;
            } else {
                return vector<int> {lo + 1, hi + 1};
            }
        }
        return vector<int> {-1, -1};
        
    }
};
