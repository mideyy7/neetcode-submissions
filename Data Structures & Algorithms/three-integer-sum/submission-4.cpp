class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++) {
            while (i > 0 && i < nums.size() - 2 && nums[i - 1] == nums[i]) i++;
            int target = -nums[i];

            int lo = i + 1;
            int hi = nums.size() - 1;

            while (lo < hi) {
                if (nums[lo] + nums[hi] == target) {
                    result.push_back({nums[i], nums[lo], nums[hi]});
                    lo += 1;
                    while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                } else if (nums[lo] + nums[hi] > target) {
                    hi -= 1;
                } else {
                    lo += 1;
                }
             }

        }
        return result;  
    }
};
