class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> mp;
        vector<int> result;
        for (int num : nums) {
            mp[num] += 1;
            if (mp[num] == n + 1) result.push_back(num);
        }
        return result;
    }
};