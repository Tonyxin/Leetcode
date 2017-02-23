/*
问题描述：
给定一组非负数，返回能组成的最大值
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

解决方法：
1、先将数字转化为字符串；
2、将字符串进行排序，比较器为哪个起头大哪个起头
*/

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())    return "";
		vector<string> nums_str;
		int sum = 0;
		//先将数字转化为字符串
		for (auto &c : nums)
		{
			nums_str.push_back(to_string(c));
			sum += c;
		}
		if (!sum)    return "0";
		//将字符串进行排序，比较器为哪个起头大哪个起头
		sort(nums_str.begin(), nums_str.end(), [](string &a, string &b){return a + b>b + a; });
		string result;
		for (const auto &c : nums_str)
			result += c;
		return result;
	}
};