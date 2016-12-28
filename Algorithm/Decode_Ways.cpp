/*
����������
A-Z��������ķ�ʽ���룬����һ���ַ�����������ķ�ʽ�ж�����
'A' -> 1
'B' -> 2
...
'Z' -> 26

���һ��"12"�����Է����AB��Ҳ������L���������ַ�ʽ

���������
����һ����̬�滮���⣨DP��
�����[i]λ�������Ǵ�[i-1]��������õ���Ҳ�����Ǵ�[i-2]��������õ�
��������£�result[i] = result[i - 1]+result[i - 2]��
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