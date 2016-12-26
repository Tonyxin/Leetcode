/*
问题描述：
给一个正整数n，可以有2^n个二进制数，相邻二进制数只能有1位不同

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

解决方法：
采用递归的方式：
n=1					0
						1
n=2				  00				
					  01
					  11
					  10
n=3				000
					001
					011
					010
					110
					111
					101
					100
n+1是在n的结果上，向下对称反折，前一位补1
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