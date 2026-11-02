class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        int maxx_s = 1;
        int maxx_n = nums[0];
        mp[nums[0]]++;

        for (int i = 1; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > maxx_s) {
                maxx_s = mp[nums[i]];
                maxx_n = nums[i];
            }
        }
        return maxx_n;   
    }
};