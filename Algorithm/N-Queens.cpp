/*
����������
n�ʺ����⣬n*n�������ϣ�ͬһ�С�һ�С�һ�Խ����ϲ���ͬʱ��2���ʺ�

���������
��Ǿ���+������������㷨���еݹ�
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (!n)  return result;
		string value(n, '.');
		vector<string> single_result(n, value);
		//���������������飬��ʾĳһ�С�ĳһ�����Խ��ߡ�ĳһ���ζԽ����ܷ����Ԫ��
		vector<bool> column(n, 1);               //�У�1��ʾ���Է���
		vector<bool> mdiagonal(2 * n - 1, 1);        //���Խ��ߣ�1��ʾ���Է���
		vector<bool> diagonal(2 * n - 1, 1);         //�ζԽ��ߣ�1��ʾ���Է���
		recur(result, single_result, 0, n, column, mdiagonal, diagonal);
		return result;
	}
	//���õݹ�ķ�ʽʵ�֣����ڵ�1�з��ã�Ȼ��ŵ�2�С����������ǹ�����������㷨��
	//�ݹ������־��
	//    �ɹ��������ж�������Q��
	//    ʧ�ܣ�ĳһ�в��ܷ�Q��
	void recur(vector<vector<string>> &result, vector<string> single_result, int i, const int &n, vector<bool> column, vector<bool> mdiagonal, vector<bool> diagonal)
	{
		if (i == n)
		{
			result.push_back(single_result);
			return;
		}
		for (int j = 0; j<n; j++)
		{
			if (column[j] && mdiagonal[i - j + n - 1] && diagonal[i + j])            //�õ�δ���ù�
			{
				single_result[i][j] = 'Q';                                //����Q�����б��
				column[j] = mdiagonal[i - j + n - 1] = diagonal[i + j] = 0;
				recur(result, single_result, i + 1, n, column, mdiagonal, diagonal);    //������һ�н��еݹ�
				single_result[i][j] = '.';                                //ͬһ���ѭ�����ǵý�����ͱ�ǻָ�
				column[j] = mdiagonal[i - j + n - 1] = diagonal[i + j] = 1;
			}//if
		}//for
	}
};