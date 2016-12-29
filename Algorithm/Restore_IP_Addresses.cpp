/*
问题描述：
将给定的数字字符串，转换为所有可能的IP地址
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

解决方法：
采用DPL方式，1位、2位、3位都可能对应成IP地址
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
			single_str.pop_back();      //删除最后的'.
			result.push_back(single_str);
			return;
		}
		if (IP_pos == 4 && str_pos != s.size())
			return;
		if (str_pos == s.size() && IP_pos != 4)
			return;
		string str_tmp;
		//该部分可以只有1位
		str_tmp = s.substr(str_pos, 1);
		recur(result, s, single_str + str_tmp + ".", str_pos + 1, IP_pos + 1);
		//该部分可以有2位
		if (str_pos<s.size() - 1 && s[str_pos] != '0')         //这里要排除掉首位是0的情况
		{
			str_tmp = s.substr(str_pos, 2);
			recur(result, s, single_str + str_tmp + ".", str_pos + 2, IP_pos + 1);
		}
		//该部分可以有3位
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