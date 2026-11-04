class Solution {
public:
    string minWindow(string s, string t) {
        // -1 to 0 complete
        // 1 to -1 incomplete

        vector<int> v_t(52, 0);
        for (char c : t) {
            v_t[index(c)]--;
        }

        int check = 0;
        for (int i = 0; i < 52; i++) {
            if (v_t[i] < 0) check++;
        }

        int l = 0;
        int min_length = INT_MAX;
        int min_start = -1;
        for (int r = 0; r < s.size(); r++) {
            v_t[index(s[r])]++;
            if (v_t[index(s[r])] == 0) check--;
            while (check == 0) {
                if (r - l + 1 < min_length) {
                    min_length = r - l + 1;
                    min_start = l;
                }
                v_t[index(s[l])]--;
                if (v_t[index(s[l])] == -1) check++;
                l++;
            }
        }

        if (min_start == -1) return "";
        return s.substr(min_start, min_length);
        
    }


    int index(char c){
        if(c >= 'a' && c <= 'z') return c - 'a';
        return c - 'A' + 26;
    }
    
};
