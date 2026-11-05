class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operands = {"+", "/", "*", "-"};
        stack<int> st;

        for (string& t : tokens) {
            if (operands.count(t)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(get_value(a, b, t));
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
        
    }


    int get_value(int m, int n, string& c) {
        if (c == "+") {
            return m + n;
        } else if (c == "-") {
            return m - n;
        } else if (c == "*") {
            return m * n;
        } else if (c == "/") {
            return m / n;
        }
        return -1;
    }
};
