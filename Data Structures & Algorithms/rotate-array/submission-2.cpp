class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0 || n == 0) return;
        k %= n;
        reverse(0, n - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, n - 1, nums);
        
    }

    void reverse(int l, int r, vector<int>& nums) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};