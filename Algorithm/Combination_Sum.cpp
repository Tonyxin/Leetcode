/*
问题描述：
给定一个正整数集合s和一个目标数t，在s中寻找几个数a、b、c，使得a+b+c=s；
所取的数可以重复使用，不限制加数的个数，但是重复的选项要排除

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

解决方法：
采用栈的方式保存单次结果，
首先入栈s[0]，不断入栈，直到n1*s[0]>=target；
出栈1个s[0]，不断入栈s[1]，直到n1*s[0]+n2*s[1]>=target；
出栈1个s[1]，不断入栈s[2].........
程序也是一个不断递归的操作.......
*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;				//为最终结果
		vector<int> single_result;					//为result中的元素
		if (candidates.empty())
			return result;
		sort(candidates.begin(), candidates.end());		//先进行从小到大排序操作，防止出现重复，并能减少遍历次数
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
		//应该从number开始遍历
		for (int i = number; i < candidates.size() && candidates[i] <= target; i++)
		{
			single_result.push_back(candidates[i]);
			//添加一个数，向下进行递推操作（后面添加的数只能是自己或者是自己后面的数）
			sum(candidates, result, single_result, target - candidates[i], i);			//注意，这里还是可以从nunber开始
			single_result.pop_back();
		}
	}
};