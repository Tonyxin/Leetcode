/*
问题描述：
给一个二维矩阵，和左上角（row1,col1）、右下角（row2,col2）两个点，计算围成矩阵的和

解决方法：
预先设置一个矩阵，sum[i][j]是matrix[0][0]和matrix[i][j]组成矩阵的累加和，
（row1,col1）、（row2,col2）组成矩阵的累加和为
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