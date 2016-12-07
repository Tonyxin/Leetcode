/*
����������
����һ������������s��һ��Ŀ����t����s��Ѱ�Ҽ�����a��b��c��ʹ��a+b+c=s��
��ȡ�������Բ��ظ�ʹ�ã������Ƽ����ĸ����������ظ���ѡ��Ҫ�ų�

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
���������
�ȴ�С��������
����ջ�ķ�ʽ���浥�ν����
������ջs[0]��s[1]��s[2]��s[3]��ֱ��s[0]+s[1]+...+s[i]>=target��
��ջs[i]����ջs[i+1]���ٽ����ж�....
���ϵĳ�ջ����ջ�����ϳ��ԵĹ���
����Ҳ��һ�����ϵݹ�Ĳ���.......
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> single_result;
		vector<vector<int>> result;
		if (candidates.empty())
			return result;
		sort(candidates.begin(), candidates.end());
		sum2(candidates, result, single_result, target, 0);
		return result;
	}
private:
	void sum2(const vector<int> &candidates, vector<vector<int>> &result
		, vector<int> &single_result, int target, int number)
	{
		if (target == 0)
		{
			result.push_back(single_result);
			return;
		}
		for (int i = number; i < candidates.size() && candidates[i] <= target; i++)
		{
			if (i != number&&candidates[i] == candidates[i - 1])
				continue;
			single_result.push_back(candidates[i]);
			//���һ���������½��е��Ʋ�����������ӵ���ֻ�����Լ��������Լ����������
			sum2(candidates, result, single_result, target - candidates[i], i + 1);
			single_result.pop_back();
		}
	}
};