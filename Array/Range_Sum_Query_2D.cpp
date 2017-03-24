/*
����������
��һ����ά���󣬺����Ͻǣ�row1,col1�������½ǣ�row2,col2�������㣬����Χ�ɾ���ĺ�

���������
Ԥ������һ������sum[i][j]��matrix[0][0]��matrix[i][j]��ɾ�����ۼӺͣ�
��row1,col1������row2,col2����ɾ�����ۼӺ�Ϊ
sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
+-----+--+---+   
|	       |    |      |
|	       |    |      |
+-----+--+     |
|          |    |      |
+-----+--+     |
|                      |
|                      |
+--------------+
*/

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		int m = matrix.size();
		if (!m)  mtx.clear();
		else
		{
			int n = matrix[0].size();
			if (!n)  mtx.clear();
			else
			{
				mtx.assign(m + 1, vector<int>(n + 1, 0));
				for (int i = 1; i <= m; i++)
				{
					for (int j = 1; j <= n; j++)
						mtx[i][j] = matrix[i - 1][j - 1] + mtx[i - 1][j] + mtx[i][j - 1] - mtx[i - 1][j - 1];
				}//for
			}//else
		}//else
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (mtx.empty()) return 0;
		return mtx[row2 + 1][col2 + 1] - mtx[row1][col2 + 1] - mtx[row2 + 1][col1] + mtx[row1][col1];
	}

	vector<vector<int>> mtx;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/