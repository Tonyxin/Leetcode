/*
问题描述：
n皇后问题，n*n的棋盘上，同一行、一列、一对角线上不能同时有2个皇后

解决方法：
标记矩阵+广度优先搜索算法进行递归
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (!n)  return result;
		string value(n, '.');
		vector<string> single_result(n, value);
		//额外设置三个数组，表示某一列、某一条主对角线、某一条次对角线能否放置元素
		vector<bool> column(n, 1);               //列，1表示可以放置
		vector<bool> mdiagonal(2 * n - 1, 1);        //主对角线，1表示可以放置
		vector<bool> diagonal(2 * n - 1, 1);         //次对角线，1表示可以放置
		recur(result, single_result, 0, n, column, mdiagonal, diagonal);
		return result;
	}
	//采用递归的方式实现，先在第1行放置，然后放第2行。。。（就是广度优先搜索算法）
	//递归结束标志：
	//    成功：所有行都放置了Q；
	//    失败：某一行不能放Q；
	void recur(vector<vector<string>> &result, vector<string> single_result, int i, const int &n, vector<bool> column, vector<bool> mdiagonal, vector<bool> diagonal)
	{
		if (i == n)
		{
			result.push_back(single_result);
			return;
		}
		for (int j = 0; j<n; j++)
		{
			if (column[j] && mdiagonal[i - j + n - 1] && diagonal[i + j])            //该点未放置过
			{
				single_result[i][j] = 'Q';                                //放上Q，进行标记
				column[j] = mdiagonal[i - j + n - 1] = diagonal[i + j] = 0;
				recur(result, single_result, i + 1, n, column, mdiagonal, diagonal);    //进入下一行进行递归
				single_result[i][j] = '.';                                //同一层次循环，记得将矩阵和标记恢复
				column[j] = mdiagonal[i - j + n - 1] = diagonal[i + j] = 1;
			}//if
		}//for
	}
};