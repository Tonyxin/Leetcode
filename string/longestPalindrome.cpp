/*
问题描述：
给定字符串s，寻找字符串s内的最长回文子串
Example1:
Input: "babad"
Output: "bab"
Example2:
Input: "cbbd"
Output: "bb"

解决方法：
针对Example1，遍历s内的每一个字符，向两边展开，判断两边的字符是否相等
针对Example2，遍历s内的每相邻两个字符，向两边展开，判断两边的字符是否相等
*/


class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		string result(s, 0, 1);
		auto itr_begin = s.begin();
		auto itr_end = s.end();
		for (auto itr = itr_begin; itr != itr_end - 1; itr++)
		{
			string first = checkPalindrome(s, itr, itr);
			if (first.size()>result.size())
				result = first;
			string second = checkPalindrome(s, itr, itr + 1);
			if (second.size()>result.size())
				result = second;
		}
		return result;
	}
private:
	string checkPalindrome(const string &s, string::const_iterator left, string::const_iterator right)
	{
		string result;
		auto itr_begin = s.begin();
		auto itr_end = s.end();
		while ((left != itr_begin) && (right != itr_end - 1) && (*left == *right))
		{
			left--;
			right++;
		}
		if (*left != *right)
		{
			left++;
			right--;
		}
		result = s.substr(left - itr_begin, right - left + 1);
		return result;
	}
};