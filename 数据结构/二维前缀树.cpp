class MatrixSum {
private:
    vector<vector<int>> sum;

public:
    MatrixSum(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // ע�⣺��� matrix[i][j] ��Χ�ܴ���Ҫʹ�� long long
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }
    }

    // �������Ͻ��� (r1,c1) ���½��� (r2-1,c2-1) ���Ӿ���Ԫ�غͣ�����ǰ׺�͵�����ҿ���
    int query(int r1, int c1, int r2, int c2) {
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    }

    // ����㲻ϰ������ҿ���Ҳ��������д
    // �������Ͻ��� (r1,c1) ���½��� (r2,c2) ���Ӿ���Ԫ�غ�
    int query2(int r1, int c1, int r2, int c2) {
        return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
    }
};
