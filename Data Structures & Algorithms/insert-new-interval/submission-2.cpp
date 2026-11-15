class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (newInterval[1] < interval[0]) {
                result.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++) {
                    result.push_back(intervals[j]);
                }
                return result;
            } else if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            } else {
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
            }
        }
        result.push_back(newInterval);
        return result;
        
    }
};
