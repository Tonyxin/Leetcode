/*
问题描述：
给一系列非负数，初始在第一个位置，每个元素代表能向后走的最大步长，求解能否走到最后

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

解决方法：
设置reach表示当前能够走到的最大距离，遍历[...reach]，不断修改reach的值，检查是否能走到最后
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return false;
		int i = 0;
		//reach表示当前能够走到的最大距离
		//遍历[...reach]，不断修改reach的值
		//检查是否能走到最后
		//根本不用管0的陷阱
		for (int reach = 0; i < n && i <= reach; ++i)
			reach = max(i + nums[i], reach);
		return i == n;
	}
};