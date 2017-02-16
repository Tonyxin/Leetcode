/*
����������
�����ַ���s����s�л����Ӵ��ָ����
For example, given s = "aab",
Return
[
["aa","b"],
["a","a","b"]
]

���������
//���õݹ�ķ�ʽ��
//ѭ��0<=i<end�����[0,i]�ǻ��ģ�push_back���ݹ�
//      ѭ��i+1<=j<end,���[i+1,k]�ǻ��ģ�push_back���ݹ�
//              ������
//���ڵ������ַ�Ҳ�ǻ��ģ����������ĵݹ鷽ʽ�ܽ�����ȥ
*/

class Solution {
public:
	//���õݹ�ķ�ʽ��
	//ѭ��0<=i<end�����[0,i]�ǻ��ģ�push_back���ݹ�
	//      ѭ��i+1<=j<end,���[i+1,k]�ǻ��ģ�push_back���ݹ�
	//              ������
	//���ڵ������ַ�Ҳ�ǻ��ģ����������ĵݹ鷽ʽ�ܽ�����ȥ
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> single_result;
		recur(result, single_result, s, 0);
		return result;
	}
	void recur(vector<vector<string>>& result, vector<string> single_result, const string &s, int pos)
	{
		if (pos == s.size())           //�ݹ����
		{
			result.push_back(single_result);
			return;
		}
		for (int i = pos; i<s.size(); i++)
		{
			if (isPalindrome(s, pos, i))       //[pos,i]�ǻ��Ľṹ�����棬�Ժ�һ���ֵ��ַ����ݹ�
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