class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; i++) free_rooms.push(i);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy_rooms;
        vector<int> count(n);

        for (vector<int>& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
                free_rooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }
            int room;
            if (!free_rooms.empty()) {
                room = free_rooms.top(); free_rooms.pop();
                busy_rooms.push({end, room});
            } else {
                pair<int,int> p = busy_rooms.top(); busy_rooms.pop();
                room = p.second;
                busy_rooms.push({p.first + (end - start), room});
            }
            count[room]++;
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[result]) result = i;
        }
        return result;



    }
};