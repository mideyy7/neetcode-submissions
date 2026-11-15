class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval_a, const vector<int>& interval_b){
            return interval_a[0] < interval_b[0];
        });

        int count = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (interval[0] >= prev_end) {
                prev_end = interval[1];
            } else {
                count++;
                prev_end = min(prev_end, interval[1]);
            }
        }
        return count;
        
    }
};
