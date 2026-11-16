class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        int n = queries.size();
        vector<int> query(n);
        iota(query.begin(), query.end(), 0);
        sort(query.begin(), query.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {length_of_interval, end_time}
        vector<int> result(n);
        int i = 0;
        for (int que : query) {
            int q = queries[que]; // smallest query at the moment
            while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop(); 
            if (pq.empty()) {
                result[que] = -1;
            } else {
                result[que] = pq.top().first;
            }
        }
        return result;
    }
};
