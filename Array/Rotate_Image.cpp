/*
问题描述：
给一个n×n的二维矩阵，实现矩阵旋转90°
要求不另外设置矩阵
解决方法：
现对矩阵沿对角线翻转一次，再沿竖直对称线翻转一次
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		if (!size)
			return;
		//先沿对角线反转一次
		for (int i = 0; i<size - 1; i++)
		{
			for (int j = (i + 1); j<size; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}//for
		}//for
		//再沿竖直对称线反转一次
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size / 2; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][size - 1 - j];
				matrix[i][size - 1 - j] = tmp;
			}//for
		}//for
	}
};