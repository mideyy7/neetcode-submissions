class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int, vector<int>> pq; //[profit, capital] highest profit and lowest capital
        // sort by capital and profit
        int n = profits.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        int i = 0;
        while (k--) {
            while (i < n && capital[order[i]] <= w) {
                pq.push(profits[order[i]]);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;  
    }
};