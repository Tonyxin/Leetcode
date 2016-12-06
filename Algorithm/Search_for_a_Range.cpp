/*
问题描述：
给定一个有序整数数组s和一个整数t，返回s中等于t的元素范围
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

解决方法：
采用二分搜索算法（binary search），范围为i，j
寻找左边界位置：
mid=(i+j)/2;							//寻找左边界，应该尽量往左边确定搜索范围
s[mid]>t，j=--mid;
s[mid]<t，i=++mid;
s[mid]=t，j=mid;
寻找右边界位置：
mid=(i+j+1)/2;						//寻找右边界，应该尽量往右边确定搜索范围
s[mid]>t，j=--mid;
s[mid]<t，i=++mid;
s[mid]=t，i=mid;
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1, -1 };
		if (nums.empty())
			return result;
		int begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]>target)    end = --mid;
			else if (nums[mid]<target)    begin = ++mid;
			else    end = mid;
		}
		if (nums[begin] == target)
			result[0] = begin;
		else
			return{ -1, -1 };
		begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int mid = (begin + end + 1) / 2;
			if (nums[mid]>target)    end = --mid;
			else if (nums[mid]<target)    begin = ++mid;
			else    begin = mid;
		}
		result[1] = begin;
		return result;
	}
};