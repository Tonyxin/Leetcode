/*
����������
����һ������������s��һ��Ŀ����t����s��Ѱ�Ҽ�����a��b��c��ʹ��a+b+c=s��
��ȡ���������ظ�ʹ�ã������Ƽ����ĸ����������ظ���ѡ��Ҫ�ų�

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

���������
����ջ�ķ�ʽ���浥�ν����
������ջs[0]��������ջ��ֱ��n1*s[0]>=target��
��ջ1��s[0]��������ջs[1]��ֱ��n1*s[0]+n2*s[1]>=target��
��ջ1��s[1]��������ջs[2].........
����Ҳ��һ�����ϵݹ�Ĳ���.......
*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;				//Ϊ���ս��
		vector<int> single_result;					//Ϊresult�е�Ԫ��
		if (candidates.empty())
			return result;
		sort(candidates.begin(), candidates.end());		//�Ƚ��д�С���������������ֹ�����ظ������ܼ��ٱ�������
		sum(candidates, result, single_result, target, 0);		
		return result;
	}
private:
	void sum(const vector<int> &candidates, vector<vector<int>> &result
		, vector<int> &single_result, int target, int number)
	{
		if (target == 0)
		{
			result.push_back(single_result);
			return;
		}
		//Ӧ�ô�number��ʼ����
		for (int i = number; i < candidates.size() && candidates[i] <= target; i++)
		{
			single_result.push_back(candidates[i]);
			//���һ���������½��е��Ʋ�����������ӵ���ֻ�����Լ��������Լ����������
			sum(candidates, result, single_result, target - candidates[i], i);			//ע�⣬���ﻹ�ǿ��Դ�nunber��ʼ
			single_result.pop_back();
		}
	}
};