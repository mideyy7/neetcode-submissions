class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long check = (long long)target - nums[i] - nums[j];

                int lo = j + 1;
                int hi = n - 1;

                while (lo < hi) {
                    if (nums[lo] + nums[hi] == check) {
                        result.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                    } else if ( nums[lo] + nums[hi] > check) {
                        hi--;
                    } else {
                        lo++;
                    }
                }
            }
        }
        return result;   
    }
};