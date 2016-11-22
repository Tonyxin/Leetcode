/*
问题描述：
给定1个字符串，寻找没有重复字母的最长子串
例子:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.

解决方法：
使用两个迭代器substr_begin、substr_end，两个迭代器之间的子串为无重复字母的子串；
递增substr_end，在[substr_begin,substr_end)中寻找有没有*itr==*substr_end，如果有，则substr_begin=itr+1;
*/


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		int result = 0;
		auto substr_begin = s.begin();
		auto substr_end = substr_begin + 1;
		while (substr_end != s.end())
		{
			for (auto itr = substr_begin; itr != substr_end; itr++)
			{
				if (*itr == *substr_end)
				{
					result = (result>(substr_end - substr_begin)) ? result : (substr_end - substr_begin);
					substr_begin = itr + 1;
					break;
				}
			}
			substr_end++;
		}
		result = (result>(substr_end - substr_begin)) ? result : (substr_end - substr_begin);
		return result;
	}
};