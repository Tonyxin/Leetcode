/*
����������
�����ַ���s��Ѱ���ַ���s�ڵ�������Ӵ�
Example1:
Input: "babad"
Output: "bab"
Example2:
Input: "cbbd"
Output: "bb"

���������
���Example1������s�ڵ�ÿһ���ַ���������չ�����ж����ߵ��ַ��Ƿ����
���Example2������s�ڵ�ÿ���������ַ���������չ�����ж����ߵ��ַ��Ƿ����
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