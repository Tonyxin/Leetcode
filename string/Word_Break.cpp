/*
����������
�����ǿ��ַ���s�ͷǿ��ַ����ֵ�wordDict���ж�s�ܷ����wordDict�еĵ��ʽ��зָ�
For example, given
s = "leetcode",
dict = ["leet", "code"].

���������
��̬�滮���⣻
�����趨һ��bool posAccessable[]���飬��ʾs�е�i��λ���Ƿ�ɴ
s[i]�ɴ�������ǣ�����0<=j<i��s[j]�ɴﲢ��s[j+1,i]��wordDict�п����ҵ�
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
				if (posAccessable[j])		//s[j]�ɴ�
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