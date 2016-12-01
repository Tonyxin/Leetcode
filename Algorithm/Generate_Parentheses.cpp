/*
����������
��n�����ţ�����n��������ϵ����п���
For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

���������
��������������left_backets��ʾ��������ӵ�'('��right_backets��ʾ����Ҫ��ӵ�')'��
��left_backets>0ʱ�����ǻ����Լ������'('����left_backets��С��������Ҫ�����')'����right_backets+1��
��right_backets>0ʱ�����ǿ��Լ������')'��֮��left_backets���䣬right_backets��1
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