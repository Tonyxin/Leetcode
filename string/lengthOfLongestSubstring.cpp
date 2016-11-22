/*
����������
����1���ַ�����Ѱ��û���ظ���ĸ����Ӵ�
����:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.

���������
ʹ������������substr_begin��substr_end������������֮����Ӵ�Ϊ���ظ���ĸ���Ӵ���
����substr_end����[substr_begin,substr_end)��Ѱ����û��*itr==*substr_end������У���substr_begin=itr+1;
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