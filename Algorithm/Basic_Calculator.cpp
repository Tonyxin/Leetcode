/*
����������
һ���ַ����к������֡�+��-���ո�д��������
For example,
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

���������
��׺���ʽ
*/

class Solution {
public:
	//�뷨�����ú�׺���ʽ
	int calculate(string s) {
		vector<string> suf_expr;					//�洢��׺���ʽ
		string sub_expr;								//�洢�����ַ���
		stack<char> operator_stack;			//�洢�����
		for (auto &c : s)
		{
			if (c == ' ') continue;
			//��������֣�����洢�������ַ�����
			else if (c - '0' >= 0 && c - '9' <= 0)
				sub_expr += c;
			else
			{
				//�������ţ�����֮ǰ�������ѽ�ֹ���������ַ��������׺���ʽ��
				if (!sub_expr.empty())
					suf_expr.push_back(sub_expr);
				sub_expr.clear();       //ע�⽫�����ַ������
				//���������ţ�����������ϳ�ջ��ֱ������������
				if (c == ')')
				{
					while (!operator_stack.empty())
					{
						auto opt = operator_stack.top();
						operator_stack.pop();
						if (opt == '(')   break;
						//��ջ����������浽��׺���ʽ��
						suf_expr.push_back(string(1, opt));
					}
				}
				//���������ţ�ֱ����ջ
				else if (c == '(')
					operator_stack.push(c);
				//����+��-��������Ƚ�ջ���������ջ���Լ�����ջ
				else
				{
					if (!operator_stack.empty() && operator_stack.top() != '(')
					{
						auto opt = operator_stack.top();
						operator_stack.pop();
						suf_expr.push_back(string(1, opt));
					}
					operator_stack.push(c);
				}//else
			}//else
		}//for
		//�����ַ������գ����������׺���ʽ
		if (!sub_expr.empty())
			suf_expr.push_back(sub_expr);
		sub_expr.clear();
		//������ջ���գ����������׺���ʽ
		while (!operator_stack.empty())
		{
			auto opt = operator_stack.top();
			operator_stack.pop();
			suf_expr.push_back(string(1, opt));
		}//while
		stack<int> ans;     //���ջ
		for (auto &c : suf_expr)
		{
			//������������������ջ�������ֽ������㣬�������ջ
			if (c == "+" || c == "-")
			{
				auto num2 = ans.top();
				ans.pop();
				auto num1 = ans.top();
				ans.pop();
				if (c == "+")
					ans.push(num1 + num2);
				if (c == "-")
					ans.push(num1 - num2);
			}
			//��������ִ���������ջ
			else
				ans.push(stoi(c));
		}
		return ans.top();
	}
};