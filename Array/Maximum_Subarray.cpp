/*
问题描述：
给一列整数，求连续子串和的最大值
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
解决方法：
在加下一个数前，判断之前元素和是否小于0，若小于0，之前的全部舍弃；
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int ans = nums[0];
		int sum = 0;
		for (const auto &c : nums)
		{
			if (sum<0)   sum = 0;      //在加这个数之前，先看之前的和是否小于0,若小于零，之前的全部舍弃
			sum += c;
			if (ans<sum) ans = sum;    //结果始终为sum的最大值
		}
		return ans;
	}
};