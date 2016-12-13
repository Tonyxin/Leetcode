/*
����������
��һ��m*n�ľ����ڵ�Ԫ�أ���˳ʱ�뷽���������
For example,
Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

���������
������(t)����(b)����(l)����(r)�ĸ��߽�Ǳ꣬ÿ�����һ�л�һ�����޸ĽǱ��ֵ��
ѭ����ֹ��־t>b||l>r
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty())
			return ans;
		int m = matrix.size();            //��    
		int n = matrix[0].size();         //��
		vector<int> result(m*n, 0);      //�����ʼ������ֵ��push_back��ʱ��Ҫ��
		int l = 0, r = n - 1, t = 0, b = m - 1;        //ÿ��ѭ�����������±߽�
		int index = 0;    //result���±�
		while (l <= r&&t <= b)
		{
			for (int i = l; i <= r; i++)                   //���������������һ��
				result[index++] = matrix[t][i];
			t++;        //���ϱ߽�+1����С��Χ
			if (t>b) break;
			else
			{
				for (int i = t; i <= b; i++)                   //���ϵ���������ұ�һ��
					result[index++] = matrix[i][r];
				r--;        //���ұ߽�-1����С��Χ
			}
			if (l>r) break;
			else
			{
				for (int i = r; i >= l; i--)               //���ҵ������������һ��
					result[index++] = matrix[b][i];
				b--;    //�±߽�-1����С��Χ
			}
			if (t>b) break;
			else
			{
				for (int i = b; i >= t; i--)               //���µ������������һ��
					result[index++] = matrix[i][l];
				l++;    //��߽�+1����С��Χ
			}
		}//while
		return result;
	}
};