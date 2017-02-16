/*
问题描述：
给定字符串s，将s中回文子串分割出来
For example, given s = "aab",
Return
[
["aa","b"],
["a","a","b"]
]

解决方法：
//采用递归的方式：
//循环0<=i<end，如果[0,i]是回文，push_back，递归
//      循环i+1<=j<end,如果[i+1,k]是回文，push_back，递归
//              。。。
//由于单个的字符也是回文，所以这样的递归方式能进行下去
*/

class Solution {
public:
	//采用递归的方式：
	//循环0<=i<end，如果[0,i]是回文，push_back，递归
	//      循环i+1<=j<end,如果[i+1,k]是回文，push_back，递归
	//              。。。
	//由于单个的字符也是回文，所以这样的递归方式能进行下去
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> single_result;
		recur(result, single_result, s, 0);
		return result;
	}
	void recur(vector<vector<string>>& result, vector<string> single_result, const string &s, int pos)
	{
		if (pos == s.size())           //递归结束
		{
			result.push_back(single_result);
			return;
		}
		for (int i = pos; i<s.size(); i++)
		{
			if (isPalindrome(s, pos, i))       //[pos,i]是回文结构，保存，对后一部分的字符串递归
			{
				single_result.push_back(s.substr(pos, i - pos + 1));
				recur(result, single_result, s, i + 1);
				single_result.pop_back();
			}
		}
	}
	bool isPalindrome(const string &s, int start, int end)
	{
		while (start <= end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};