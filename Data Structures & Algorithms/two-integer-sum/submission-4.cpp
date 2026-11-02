class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);

        sort(indexes.begin(), indexes.end(), [&](const int a, const int b) {
            return nums[a] < nums[b];
        });

        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int i = indexes[lo];
            int j = indexes[hi];
            if (nums[i] + nums[j] == target) {
                return vector<int> {min(i, j), max(i, j)};
            } else if (nums[i] + nums[j] > target) {
                hi -= 1;
            } else {
                lo += 1;
            }
        }
        return vector<int> {-1,-1};




        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return vector<int> {i, j};
        //         }
        //     }
        // }
        // return vector<int> {-1,-1};
    }
};
