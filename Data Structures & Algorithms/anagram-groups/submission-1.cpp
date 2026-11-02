class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map string to vector of strings

        unordered_map<string, vector<string>> mp;
        for (string& s : strs) {
            vector<int> temp(26, 0);
            for (int c : s) {
                temp[c - 'a']++;
            }
            mp[string(temp.begin(), temp.end())].push_back(s);
        }

        vector<vector<string>> result;
        for (auto [key, value] : mp) {
            result.push_back(value);
        }
        return result;  
    }
};
