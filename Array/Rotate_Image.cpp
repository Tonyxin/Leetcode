/*
����������
��һ��n��n�Ķ�ά����ʵ�־�����ת90��
Ҫ���������þ���
���������
�ֶԾ����ضԽ��߷�תһ�Σ�������ֱ�Գ��߷�תһ��
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		if (!size)
			return;
		//���ضԽ��߷�תһ��
		for (int i = 0; i<size - 1; i++)
		{
			for (int j = (i + 1); j<size; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}//for
		}//for
		//������ֱ�Գ��߷�תһ��
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