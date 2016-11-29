/*
问题描述：
给定n个整数的集合S，从S中寻找三个数a、b、c，使得a+b+c=0，寻找所有的不重复的{a、b、c}集合

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

解决方法：
先对S进行从小到大的排序，遍历S，对每一个a，在剩余的集合中寻找b、c，使得b+c=target=0-a
使用两个指针i、j，分别指向首尾元素，
若S[i]+S[j]<target，或者S[i]==S[i-1]，则i++;
若S[i]+S[j]>target，或者S[j]==S[j+1]，则j--;
若S[i]+S[j]==target，则i++、j--
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size()<3)
			return result;
		sort(nums.begin(), nums.end());
		auto itr_begin = nums.begin();
		auto itr_end = nums.end();
		for (auto itr1 = itr_begin; itr1 != itr_end - 2 && (*itr1) <= 0; itr1++)
		{
			if (itr1 != itr_begin&&*itr1 == *(itr1 - 1))
				continue;
			auto itr2 = itr1 + 1;
			auto itr3 = itr_end - 1;
			int target = 0 - (*itr1);
			int sum = (*itr2) + (*itr3);
			for (; itr2<itr3; sum = (*itr2) + (*itr3))
			{
				if (sum<target || (itr2 != itr1 + 1 && (*itr2) == (*(itr2 - 1))))  itr2++;
				else if (sum>target || (itr3 != itr_end - 1 && (*itr3) == (*(itr3 + 1))))  itr3--;
				else    result.push_back({ *itr1, *itr2++, *itr3-- });
			}
		}
		return result;
	}
};