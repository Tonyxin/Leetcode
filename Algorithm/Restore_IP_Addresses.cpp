/*
����������
�������������ַ�����ת��Ϊ���п��ܵ�IP��ַ
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

���������
����DPL��ʽ��1λ��2λ��3λ�����ܶ�Ӧ��IP��ַ
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int length = s.size();
		vector<string> result;
		if (length<4 || length>12) return result;
		recur(result, s, "", 0, 0);		
		return result;
	}
private:
	void recur(vector<string> &result, const string &s, string single_str, int str_pos, int IP_pos)
	{
		if (IP_pos == 4 && str_pos == s.size())
		{
			single_str.pop_back();      //ɾ������'.
			result.push_back(single_str);
			return;
		}
		if (IP_pos == 4 && str_pos != s.size())
			return;
		if (str_pos == s.size() && IP_pos != 4)
			return;
		string str_tmp;
		//�ò��ֿ���ֻ��1λ
		str_tmp = s.substr(str_pos, 1);
		recur(result, s, single_str + str_tmp + ".", str_pos + 1, IP_pos + 1);
		//�ò��ֿ�����2λ
		if (str_pos<s.size() - 1 && s[str_pos] != '0')         //����Ҫ�ų�����λ��0�����
		{
			str_tmp = s.substr(str_pos, 2);
			recur(result, s, single_str + str_tmp + ".", str_pos + 2, IP_pos + 1);
		}
		//�ò��ֿ�����3λ
		if (str_pos<s.size() - 2 && s[str_pos] != '0')
		{
			int sum = (s[str_pos] - '0') * 100 + (s[str_pos + 1] - '0') * 10 + s[str_pos + 2] - '0';
			if (sum<256)
			{
				str_tmp = s.substr(str_pos, 3);
				recur(result, s, single_str + str_tmp + ".", str_pos + 3, IP_pos + 1);
			}
		}//if
	}
};