class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> st;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            max_length = max(max_length, r - l + 1);
        }
        return max_length;
        
    }
};
