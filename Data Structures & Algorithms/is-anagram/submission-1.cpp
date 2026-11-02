class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        vector<int> s_v(26, 0);
        vector<int> t_v(26, 0);

        for (int i = 0; i < max(s_size, t_size); i++) {
            if (i < s_size) s_v[index(s[i])]++;
            if (i < t_size) t_v[index(t[i])]++;
        }

        for (int i = 0; i < 26; i++) {
            if (s_v[i] != t_v[i]) return false;
        }
        return true;
    }

    int index(char c) {
        return c - 'a';
    }
};
