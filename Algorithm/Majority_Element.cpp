/*
问题描述：
给一个数组n，找到其中出现次数多于⌊n/2⌋的元素，假设该元素确定存在

解决方法：
Moore's voting 算法，遍历数组，选取一个数nums[i]作为maj_ele，出现时+1，否则-1，直到count=0，表明前一段数组、
nums[i]出现次数为n/2，进而说明没有一个元素出现次数多于⌊n/2⌋，因而需要在后面的数组中寻找
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int size = nums.size();
		int count = 0;
		int maj_ele = nums[0];
		for (int i = 0; i<size; i++)
		{
			if (maj_ele == nums[i])
				count++;
			else
				count--;
			if (count == 0)
				maj_ele = nums[i + 1];
		}
		return maj_ele;
	}
};