class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int min_length = INT_MAX;
        int total = 0;
        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];
            while (total >= target) {
                min_length = min(min_length, r - l + 1);
                total -= nums[l];
                l++;
            }
        }
        if (min_length == INT_MAX) return 0;
        return min_length; 
    }
};