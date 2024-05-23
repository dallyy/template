class MatrixSum {
private:
    vector<vector<int>> sum;

public:
    MatrixSum(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 注意：如果 matrix[i][j] 范围很大，需要使用 long long
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }
    }

    // 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
    int query(int r1, int c1, int r2, int c2) {
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    }

    // 如果你不习惯左闭右开，也可以这样写
    // 返回左上角在 (r1,c1) 右下角在 (r2,c2) 的子矩阵元素和
    int query2(int r1, int c1, int r2, int c2) {
        return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
    }
};

\\对角前缀和
\\https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/
int sum1[101][101];
int sum2[101][101];
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set <int> S;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];  //维护正对角线方向前缀和
                sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];  //维护副对角线方向前缀和
            }
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                S.insert(grid[i - 1][j - 1]);
                for(int k = 1; i + k <= m && i - k >= 1 && j + k <= n && j - k >= 1; ++k){
                    int a = sum1[i + k][j] - sum1[i][j - k];
                    int b = sum1[i][j + k] - sum1[i - k][j];
                    int c = sum2[i + k][j] - sum2[i][j + k];
                    int d = sum2[i][j - k] - sum2[i - k][j];
                    S.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                    //因为前缀和算边的时候多算了上下顶点一次
                }
                while(S.size() > 3) S.erase(S.begin());
            }
        }
        return vector <int> (S.rbegin(), S.rend());
    }
};

