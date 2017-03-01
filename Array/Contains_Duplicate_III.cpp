/*
问题描述：
给定一组整数nums，判断其中是否存在两个数nums[i]、nums[j]
满足|nums[i]-nums[j]|<=t且|i-j|<=k

解决方法：
//想法：设置一连续窗口w（大小为k+1），w中任意两个元素间隔均不大于k；
//      窗口内的值用multiset保存，已经自动排序好
//      每次循环时
//          1、去除头元素，即将增加nums[i]
//          2、寻找set中是否存在x，使得|nums[i]-x|<=t;
//          3、|nums[i]-x|<=t,则x>=nums[i]-t，且x<=nums[i]+t;
//          4、由于set已经从小到大排序完成，所以寻找第一个x>=nums[i]-t，如果x<=nums[i]+t，则True
//      注意int类型的取值范围
*/
class Solution {
public:
	//想法：设置一连续窗口w（大小为k+1），w中任意两个元素间隔均不大于k；
	//      窗口内的值用multiset保存，已经自动排序好
	//      每次循环时
	//          1、去除头元素，即将增加nums[i]
	//          2、寻找set中是否存在x，使得|nums[i]-x|<=t;
	//          3、|nums[i]-x|<=t,则x>=nums[i]-t，且x<=nums[i]+t;
	//          4、由于set已经从小到大排序完成，所以寻找第一个x>=nums[i]-t，如果x<=nums[i]+t，则True
	//      注意int类型的取值范围
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int size = nums.size();
		if (size<2)  return false;
		multiset<int> window;
		for (int i = 0; i<size; i++)
		{
			if (i>k) window.erase(nums[i - k - 1]);
			auto itr = window.lower_bound((double)nums[i] - (double)t);
			if (itr != window.end() && (double)*itr <= (double)nums[i] + (double)t)
				return true;
			window.insert(nums[i]);
		}
		return false;
	}
};