class NumMatrix {
    std::vector<std::vector<long long>> P;
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        P.assign(m + 1, std::vector<long long>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            long long rowSum = 0;
            for (int j = 0; j < n; ++j) {
                rowSum += matrix[i][j];
                P[i + 1][j + 1] = P[i][j + 1] + rowSum;
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        return P[r2 + 1][c2 + 1] - P[r1][c2 + 1]
             - P[r2 + 1][c1] + P[r1][c1];
    }
};