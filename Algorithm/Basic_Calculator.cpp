/*
问题描述：
一个字符串中含有数字、+、-、空格，写出运算结果
For example,
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

解决方法：
后缀表达式
*/

class Solution {
public:
	//想法：采用后缀表达式
	int calculate(string s) {
		vector<string> suf_expr;					//存储后缀表达式
		string sub_expr;								//存储数字字符串
		stack<char> operator_stack;			//存储运算符
		for (auto &c : s)
		{
			if (c == ' ') continue;
			//如果是数字，将其存储到数字字符串中
			else if (c - '0' >= 0 && c - '9' <= 0)
				sub_expr += c;
			else
			{
				//遇到符号，表明之前的数字已截止，将数字字符串存入后缀表达式中
				if (!sub_expr.empty())
					suf_expr.push_back(sub_expr);
				sub_expr.clear();       //注意将数字字符串清空
				//遇到右括号，将运算符不断出栈，直至遇到左括号
				if (c == ')')
				{
					while (!operator_stack.empty())
					{
						auto opt = operator_stack.top();
						operator_stack.pop();
						if (opt == '(')   break;
						//出栈的运算符保存到后缀表达式中
						suf_expr.push_back(string(1, opt));
					}
				}
				//遇到左括号，直接入栈
				else if (c == '(')
					operator_stack.push(c);
				//遇到+、-运算符，先将栈顶运算符出栈，自己再入栈
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
		//数字字符串不空，将其送入后缀表达式
		if (!sub_expr.empty())
			suf_expr.push_back(sub_expr);
		sub_expr.clear();
		//操作符栈不空，将其送入后缀表达式
		while (!operator_stack.empty())
		{
			auto opt = operator_stack.top();
			operator_stack.pop();
			suf_expr.push_back(string(1, opt));
		}//while
		stack<int> ans;     //结果栈
		for (auto &c : suf_expr)
		{
			//如果是运算符，连续出栈两个数字进行运算，结果再入栈
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
			//如果是数字串，将其入栈
			else
				ans.push(stoi(c));
		}
		return ans.top();
	}
};