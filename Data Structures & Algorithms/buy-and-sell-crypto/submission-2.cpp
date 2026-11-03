class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lo = 0;
        int hi = 1;
        int maxx = 0;

        while (hi < prices.size()) {
            if (prices[lo] < prices[hi]) {
                int profit = prices[hi] - prices[lo];
                maxx = max(maxx, profit);
            } else {
                lo = hi;   
            }
            hi++;
        }
        return maxx;


        
    }
};
