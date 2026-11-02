class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;
        for (int num : nums) {
            if (mp.count(num)) continue;
            int left = mp.count(num - 1) ? mp[num - 1] : 0;
            int right = mp.count(num + 1) ? mp[num + 1] : 0;
            int val = left + right + 1;
            mp[num - left] = val;
            mp[num + right] = val;
            mp[num] = val;
            result = max(result, val);   
        }
        return result; 
    }
};
