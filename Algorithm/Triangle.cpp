/*
����������
�����Ǿ�����Ѱ��һ��·��������С������һ��ѡ���Ԫ�ر�������һ������

For example, given the following triangle
[
			 [2],
           [3 ,4],
         [6, 5, 7],
       [4, 1 ,8 ,3]
]


���������
DP����
����һ�����ߵ�ֵ�⣬triangle[i][j]ֻ�ܾ���triangle[i-1][j-1]����triangle[i-1][j]�õ���
ѡȡ�����н�С��һ���ӵ�triangle[i][j]�ϣ�����triangle[i][j]ֵ��
�������½��У��������һ���ϵ���Сֵ��Ϊ���
*/


class Solution {
public:
	//�뷨��DP����
	//      ����һ�����ߵ�ֵ�⣬triangle[i][j]ֻ�ܾ���triangle[i-1][j-1]����triangle[i-1][j]�õ���
	//      ѡȡ�����н�С��һ���ӵ�triangle[i][j]�ϣ�����triangle[i][j]ֵ��
	//      �������½��У��������һ���ϵ���Сֵ��Ϊ���
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