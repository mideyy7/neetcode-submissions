class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";

        int m = word1.size();
        int n = word2.size();
        result.resize(m + n);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {
            result[k] = word1[i];
            k++;
            i++;
            result[k] = word2[j];
            k++;
            j++;
        }

        while(i < m) {
            result[k] = word1[i];
            k++;
            i++;
        }

        while (j < n) {
            result[k] = word2[j];
            j++;
            k++;
        }

        return result;
    }
};