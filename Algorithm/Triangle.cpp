/*
问题描述：
在三角矩阵中寻找一条路径，和最小，在下一行选择的元素必须与上一行相邻

For example, given the following triangle
[
			 [2],
           [3 ,4],
         [6, 5, 7],
       [4, 1 ,8 ,3]
]


解决方法：
DP问题
除了一行两边的值外，triangle[i][j]只能经过triangle[i-1][j-1]或者triangle[i-1][j]得到；
选取二者中较小的一个加到triangle[i][j]上，更新triangle[i][j]值；
依次往下进行，最终最后一行上的最小值就为结果
*/


class Solution {
public:
	//想法：DP问题
	//      除了一行两边的值外，triangle[i][j]只能经过triangle[i-1][j-1]或者triangle[i-1][j]得到；
	//      选取二者中较小的一个加到triangle[i][j]上，更新triangle[i][j]值；
	//      依次往下进行，最终最后一行上的最小值就为结果
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (!n)  return 0;
		for (int i = 1; i<n; i++)
		{
			triangle[i][0] += triangle[i - 1][0];
			for (int j = 1; j<i; j++)
				triangle[i][j] += (triangle[i - 1][j - 1]<triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j]);
			triangle[i][i] += triangle[i - 1][i - 1];
		}
		int result = triangle[n - 1][0];
		for (int j = 0; j<n; j++)
		{
			if (result>triangle[n - 1][j])
				result = triangle[n - 1][j];
		}
		return result;
	}
};