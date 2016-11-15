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
