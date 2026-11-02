class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums) {
            mp[num] ++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for (auto [key, value] : mp) {
            pq.push({value, key});
        }


        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        
    }
};
