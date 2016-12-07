/*
问题描述：
给定一个正整数集合s和一个目标数t，在s中寻找几个数a、b、c，使得a+b+c=s；
所取的数可以不重复使用，不限制加数的个数，但是重复的选项要排除

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
解决方法：
先从小到大排序
采用栈的方式保存单次结果，
不断入栈s[0]、s[1]、s[2]、s[3]，直到s[0]+s[1]+...+s[i]>=target；
出栈s[i]，入栈s[i+1]，再进行判断....
不断的出栈和入栈，不断尝试的过程
程序也是一个不断递归的操作.......
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
			//添加一个数，向下进行递推操作（后面添加的数只能是自己或者是自己后面的数）
			sum2(candidates, result, single_result, target - candidates[i], i + 1);
			single_result.pop_back();
		}
	}
};