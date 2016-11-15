/*
问题描述：
给定一组int数组Array和1个目标值target，在寻找Array中寻找两个值a、b，
使得a+b=target，返回a、b的索引
解决方法：
建立"值-索引"的map，对某一个i，寻找(target-i)在不在map中，如果在，
就返回（target-i）和i的索引
*/


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mii;
		auto itr_begin = nums.cbegin();
		auto itr_end = nums.cend();
		for (auto itr = itr_begin; itr != itr_end; ++itr)
		{
			if (mii.find(target - (*itr)) == mii.end())
				mii[*itr] = itr - itr_begin;
			else
			{
				vector<int> vec{ mii[target - (*itr)], itr - itr_begin };
				return vec;
			}
		}//for
		return vector<int>();
	}
};
