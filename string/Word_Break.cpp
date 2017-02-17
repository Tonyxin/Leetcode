/*
问题描述：
给定非空字符串s和非空字符串字典wordDict，判断s能否根据wordDict中的单词进行分割
For example, given
s = "leetcode",
dict = ["leet", "code"].

解决方法：
动态规划问题；
额外设定一个bool posAccessable[]数组，表示s中第i个位置是否可达；
s[i]可达的条件是：存在0<=j<i，s[j]可达并且s[j+1,i]在wordDict中可以找到
*/


class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int size = s.size();
		vector<bool> posAccessable(size + 1, 0);
		posAccessable[0] = 1;
		for (int i = 1; i <= size; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (posAccessable[j])		//s[j]可达
				{
					if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
					{
						posAccessable[i] = 1;
						break;
					}//if
				}//if
			}//if
		}//for
		return posAccessable[size];
	}
};