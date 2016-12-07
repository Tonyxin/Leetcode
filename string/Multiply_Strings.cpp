/*
����������
�����Ǹ����ַ���num1��num2�����������ֵĳ˻�result���ַ��������ر�
����:
num1="123123123214";
num2="789789";
������="721893791723878127389779398127893712312"

���������
����num1��num2��������result�ĳ���Ҳ�͸���Ϊ��num1.size()+num2.size()������ʼ���մ�result��
Ȼ�����ÿһλ��ˣ���������result�Ķ�Ӧλ�ϣ�ע���λ��
����"12"��"45"��
=2��5+1��10��5+2��4��10+1��10��4��10
*/


class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty())
			return "";
		if (num1 == "0" || num2 == "0")
			return "0";
		string result(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1, i_index = 0; i >= 0; i--, i_index++)
		{
			if (num1[i] == '0')
				continue;
			for (int j = num2.size() - 1, j_index = 0; j >= 0; j--, j_index++)
			{
				if (num2[j] == '0')
					continue;
				int one = (num1[i] - '0')*(num2[j] - '0') % 10;
				int ten = (num1[i] - '0')*(num2[j] - '0') / 10;
				int tmp = result[i_index + j_index] - '0' + one;
				result[i_index + j_index] = tmp % 10 + '0';
				ten = ten + tmp / 10;
				for (int k = i_index + j_index + 1; k <= num1.size() + num2.size(); k++)
				{
					if (!ten)
						break;
					int tmp = result[k] - '0' + ten;
					result[k] = tmp % 10 + '0';
					ten = tmp / 10;
				}//for
			}//for
		}//for
		reverse(result.begin(), result.end());
		result = result.substr(result.find_first_not_of('0'));
		return result;
	}
};