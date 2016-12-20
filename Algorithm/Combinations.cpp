/*
问题描述：
给定n和k，在1...n中拿出k个数，有多少中组合，给出这些组合
For example,
If n = 4 and k = 2, a solution is:
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
解决方法：
DFS，深度优先搜索算法，先遍历a[0]的取值范围，对一个a[0]，可得到a[1]取值范围，递归程序进行遍历
*/

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (k>n || k == 0)
			return result;
		vector<int> single_result(k, 0);
		recur(result, single_result, 1, n, 0, k);
		return result;
	}
private:
	//m，n为遍历范围，j为a[j]的层次
	void recur(vector<vector<int>> &result, vector<int> &single_result, int m, int n, int j, int k)
	{
		if (j == k)
		{
			result.push_back(single_result);
			return;
		}
		for (int i = m; i <= n - k + 1 + j; i++)
		{
			single_result[j] = i;
			recur(result, single_result, i + 1, n, j + 1, k);
		}
	}
};