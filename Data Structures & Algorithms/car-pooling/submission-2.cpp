class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (vector<int>& trip: trips) {
            while (!pq.empty() && pq.top().first <= trip[1]) {
                capacity += pq.top().second;
                pq.pop();
            }
            capacity -= trip[0];
            pq.push({trip[2], trip[0]});
            if (capacity < 0) return false;
        }

        return true;
    }
};