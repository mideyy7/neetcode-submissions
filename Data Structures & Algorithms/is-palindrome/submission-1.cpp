class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            while (lo < hi && !is_alphanum(s[lo])) lo++;
            while (hi > lo && !is_alphanum(s[hi])) hi--;
            char a = to_lower(s[lo]);
            char b = to_lower(s[hi]);
            if (a != b) return false;
            lo++;
            hi--;
        }
        return true;
    }

    char to_lower(char c) {
        if (c >= 'A' &&  c <= 'Z') return 'a' + (c - 'A');
        return c;
    }

    bool is_alphanum(char a) {
        char c = to_lower(a);
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        return false;
    }
};
