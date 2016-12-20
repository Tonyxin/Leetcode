/*
����������
����n��k����1...n���ó�k�������ж�������ϣ�������Щ���
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
���������
DFS��������������㷨���ȱ���a[0]��ȡֵ��Χ����һ��a[0]���ɵõ�a[1]ȡֵ��Χ���ݹ������б���
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
	//m��nΪ������Χ��jΪa[j]�Ĳ��
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