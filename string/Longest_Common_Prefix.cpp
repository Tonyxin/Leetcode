/*
问题描述：
给一个vector<string>的strs，寻找内部string的最长共同前缀
解决方法：
遍历每一个string，过程中保存最长共同前缀，没一次比较，要比较string中长度的都会变小
*/


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return string();
		string str = strs[0];
		for (int i = 1; i<strs.size(); i++)
		{
			int size_l = str.size();
			int size_r = strs[i].size();
			int size = (size_l<size_r) ? size_l : size_r;
			for (int j = 0; j <= size; j++)
			{
				if (str[j] != strs[i][j])
				{
					string tmp(str, 0, j);
					str = tmp;
				}//if
			}//for
		}//for
		return str;
	}
};