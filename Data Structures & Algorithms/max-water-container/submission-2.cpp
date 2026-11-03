class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lo = 0;
        int hi = heights.size() - 1;
        int max_area = 0;
        while (lo < hi) {
            max_area = max(max_area, min(heights[lo],heights[hi]) * (hi - lo));
            if (heights[lo] < heights[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        return max_area;    
    }
};
