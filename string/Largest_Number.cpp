/*
����������
����һ��Ǹ�������������ɵ����ֵ
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

���������
1���Ƚ�����ת��Ϊ�ַ�����
2�����ַ����������򣬱Ƚ���Ϊ�ĸ���ͷ���ĸ���ͷ
*/

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())    return "";
		vector<string> nums_str;
		int sum = 0;
		//�Ƚ�����ת��Ϊ�ַ���
		for (auto &c : nums)
		{
			nums_str.push_back(to_string(c));
			sum += c;
		}
		if (!sum)    return "0";
		//���ַ����������򣬱Ƚ���Ϊ�ĸ���ͷ���ĸ���ͷ
		sort(nums_str.begin(), nums_str.end(), [](string &a, string &b){return a + b>b + a; });
		string result;
		for (const auto &c : nums_str)
			result += c;
		return result;
	}
};