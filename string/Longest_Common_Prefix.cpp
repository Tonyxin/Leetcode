/*
����������
��һ��vector<string>��strs��Ѱ���ڲ�string�����ͬǰ׺
���������
����ÿһ��string�������б������ͬǰ׺��ûһ�αȽϣ�Ҫ�Ƚ�string�г��ȵĶ����С
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