/*
����������
����һ�������ַ������������ִ�����ĸ���ϵ����п������
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

���������
���������������DFS(Depth First Search)�㷨��"2"�е�"a"����string��
���Ŵ���"3"�е�ĳһ���ַ����ٴ���"5"�е�ĳһ���ַ�������������
�������������ٺ�������
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