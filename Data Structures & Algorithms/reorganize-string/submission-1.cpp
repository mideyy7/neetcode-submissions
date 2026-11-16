class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        for (auto [chr, cnt] : mp) {
            pq.push({cnt, chr});
        }
        string result = "";
        while (!pq.empty()) {
            pair<int,char> p = pq.top(); pq.pop();
            int size = result.size();
            if (size >= 1 && result[size - 1] == p.second) {
                if (pq.empty()) break;
                pair<int,char> t = pq.top(); pq.pop();
                t.first--;
                result += t.second;
                if (t.first) pq.push({t.first, t.second});
            }
            result += p.second;
            p.first--;
            if (p.first) pq.push({p.first, p.second});

        }

        return result.size() == s.size() ? result : "";
        
    }
};