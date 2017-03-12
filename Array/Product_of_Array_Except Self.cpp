/*
问题描述：
给n个整数数组，计算各点，除去自身的累乘结果，要求时间复杂度为O(n)
For example, given [1,2,3,4], return [24,12,8,6].

解决方法：
额外设置两个数组，保存(0,i-1)的前向累乘和（i+1,size-1）的后向累乘
*/

class Solution {
public:
	//想法：额外设置两个数组，保存(0,i-1)的前向累乘和（i+1,size-1）的后向累乘
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans;
		int size = nums.size();
		if (!size)    return ans;
		vector<int> forward_multi(size, 1);
		vector<int> backward_multi(size, 1);
		//得到各点的前向累乘
		for (int i = 1; i<size; i++)
			forward_multi[i] = forward_multi[i - 1] * nums[i - 1];
		//得到各点的后向累乘
		for (int i = size - 2; i >= 0; i--)
			backward_multi[i] = backward_multi[i + 1] * nums[i + 1];
		//计算最终结果
		for (int i = 0; i<size; i++)
			ans.push_back(forward_multi[i] * backward_multi[i]);
		return ans;
	}
};