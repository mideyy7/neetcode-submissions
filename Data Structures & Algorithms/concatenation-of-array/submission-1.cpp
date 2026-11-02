class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n * 2);
        for (int i = 0; i < ans.size(); i++) {
            if (i < n) ans[i] = nums[i];
            if (i >= n) ans[i] = nums[i - n];
        }
        return ans; 
    }
};