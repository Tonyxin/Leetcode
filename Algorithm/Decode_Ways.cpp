/*
问题描述：
A-Z按照下面的方式编码，给定一个字符串，求译码的方式有多少种
'A' -> 1
'B' -> 2
...
'Z' -> 26

如给一个"12"，可以翻译成AB，也可以是L，共有两种方式

解决方法：
这是一个动态规划问题（DP）
到达第[i]位，可以是从[i-1]单个译码得到，也可以是从[i-2]两个译码得到
正常情况下，result[i] = result[i - 1]+result[i - 2]；
*/

class Solution {
public:
	int numDecodings(string s) {
		int length = s.size();
		if (!length || s[0] == '0') return 0;
		vector<int> result(length + 1, 0);
		result[0] = 1;
		result[1] = (s[1] == '0' ? 0 : 1);
		for (int i = 2; i <= length; i++)
		{
			if (s[i] == '0')
			{
				result[i] = 0;
				continue;
			}
			result[i] = result[i - 1];
			int shiwei = s[i - 2] - '0';
			int gewei = s[i - 1] - '0';
			auto sum = shiwei * 10 + gewei;
			if (sum<27)
				result[i] += result[i - 2];
		}
		return result[length];
	}
};