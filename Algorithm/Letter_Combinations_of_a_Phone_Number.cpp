/*
问题描述：
给定一个数字字符串，返回数字代表字母集合的所有可能组合
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

解决方法：
采用深度优先搜索DFS(Depth First Search)算法，"2"中的"a"存入string后，
接着存入"3"中的某一个字符，再存入"5"中的某一个字符······
先向下搜索，再横向搜索
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return vector<string>();
		vector<string> result;
		string value(digits.size(), 0);
		addLetter(digits, result, value, 0);
		return result;
	}
private:
	vector<string> table{ " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void addLetter(const string &digits, vector<string> &ans, string &value, int level)
	{
		if (level == digits.size())
		{
			ans.push_back(value);
			return;
		}
		for (auto &c : table[digits[level] - '0'])
		{
			value[level] = c;
			addLetter(digits, ans, value, level + 1);
		}
	}
};