class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string result = check(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) {
            if (result == "") return result;
            result = check(result, strs[i]);
        }
        return result;  
    }

    string check(string& a, string& b) {
        string result = "";
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] == b[i]) {
                result += a[i];
            } else {
                return result;
            }
        }
        return result;
    }
};