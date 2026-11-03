class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return is_palindrome(lo + 1, hi, s) || is_palindrome(lo, hi - 1, s);
            }
            lo++;
            hi--;
        }
        return true;

    }

    bool is_palindrome(int lo, int hi, string& s) {
        while (lo < hi)  {
            if (s[lo] != s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
};