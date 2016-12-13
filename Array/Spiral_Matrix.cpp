/*
问题描述：
将一个m*n的矩阵内的元素，按顺时针方向螺旋输出
For example,
Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

解决方法：
设置上(t)、下(b)、左(l)、右(r)四个边界角标，每次输出一行或一列是修改角标的值，
循环终止标志t>b||l>r
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty())
			return ans;
		int m = matrix.size();            //行    
		int n = matrix[0].size();         //列
		vector<int> result(m*n, 0);      //结果初始化，赋值比push_back的时间要短
		int l = 0, r = n - 1, t = 0, b = m - 1;        //每次循环，左右上下边界
		int index = 0;    //result的下标
		while (l <= r&&t <= b)
		{
			for (int i = l; i <= r; i++)                   //从左到右输出最上面一行
				result[index++] = matrix[t][i];
			t++;        //将上边界+1，缩小范围
			if (t>b) break;
			else
			{
				for (int i = t; i <= b; i++)                   //从上到下输出最右边一行
					result[index++] = matrix[i][r];
				r--;        //将右边界-1，缩小范围
			}
			if (l>r) break;
			else
			{
				for (int i = r; i >= l; i--)               //从右到左输出最下面一行
					result[index++] = matrix[b][i];
				b--;    //下边界-1，缩小范围
			}
			if (t>b) break;
			else
			{
				for (int i = b; i >= t; i--)               //从下到上输出最左面一行
					result[index++] = matrix[i][l];
				l++;    //左边界+1，缩小范围
			}
		}//while
		return result;
	}
};