/*
问题描述：
给数组x[n]（元素均为正整数）和目标值s，在x中寻找最小的子序列，其sum>=s

解决方法：
选取[i,j]（i取0）为初始窗口（x[i]+...+x[j]>=s），之后向右移动窗口（j++），
如果sum-x[i]>=s，不断i++，缩小窗口，记录ans值
*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())    return 0;
		int i = 0, j = 0;
		int sum = nums[i];
		while (sum<s)
		{
			if (j == nums.size() - 1)
				break;
			j++;
			sum += nums[j];
		}
		if (sum<s)   return 0;       //不含有子序列
		int ans = j - i + 1;              //初始窗口，之后不断缩小
		while (1)
		{
			while (sum - nums[i] >= s)   //不断缩小窗口
			{
				sum = sum - nums[i];
				i++;
			}
			if (j - i + 1<ans)           //窗口小于答案
				ans = j - i + 1;
			if (j == nums.size() - 1)
				break;
			j++;
			sum = sum + nums[j];
		}
		return ans;
	}
};