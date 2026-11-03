class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int max_length = 0;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while ((r - l + 1) - max_count(mp) > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            max_length = max(max_length, r - l + 1);
        } 
        return max_length;  
    }

    int max_count(unordered_map<char,int>& mp) {
        int count = 0;
        for (auto [key, value] : mp) {
            if (value > count) count = value;
        }
        return count;
    }
};
