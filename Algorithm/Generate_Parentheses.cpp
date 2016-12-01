/*
问题描述：
给n对括号，产生n对括号组合的所有可能
For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

解决方法：
采用两个整数，left_backets表示还可以添加的'('，right_backets表示还需要添加的')'；
当left_backets>0时，我们还可以继续添加'('，但left_backets减小，并且需要更多的')'，即right_backets+1；
当right_backets>0时，我们可以继续添加')'，之后left_backets不变，right_backets减1
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		InsertBackets(result, "", n, 0);
		return result;
	}
private:
	void InsertBackets(vector<string> &result, string str, int left_backets, int right_backets)
	{
		if (left_backets == 0 && right_backets == 0)
		{
			result.push_back(str);
			return;
		}
		if (left_backets>0)
			InsertBackets(result, str + "(", left_backets - 1, right_backets + 1);
		if (right_backets>0)
			InsertBackets(result, str + ")", left_backets, right_backets - 1);
	}
};