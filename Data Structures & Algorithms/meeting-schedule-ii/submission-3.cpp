/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        int n = intervals.size();

        starts.resize(n);
        ends.resize(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int result = 0;
        int s = 0, e = 0;
        int count = 0;

        while (s < n) {
            if (starts[s] < ends[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            result = max(result, count);
        }
        return result;
        
    }
};
