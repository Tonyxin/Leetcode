/*
问题描述：
一个m*n的矩阵，从(1,1)走到(m,n)共有多少条路径，只能向下或者向右走

解决方法：
由于只能向下或者向右走，因此在(i,j)点的路径Path[i][j]=Path[i-1][j]+Path[i][j-1]
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
			return 0;
		vector<vector<int>> array(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				array[i][j] = array[i][j - 1] + array[i - 1][j];
				if (i == 1 && j == 1)  array[i][j] = 1;
			}
		}
		return array[m][n];
	}
};