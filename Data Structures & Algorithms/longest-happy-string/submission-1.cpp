class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            pair<int, char> p = pq.top(); pq.pop();
            int size = result.size();
            if (size >= 2 && result[size - 1] == p.second && result[size - 2] == p.second) {
                if (pq.empty()) break;
                pair<int, char> t = pq.top(); pq.pop();
                result += t.second;
                t.first--;
                if (t.first) pq.push({t.first, t.second});
            }
            p.first--;
            result += p.second;
            if (p.first) pq.push({p.first, p.second});

        }

        return result;
        
    }
};