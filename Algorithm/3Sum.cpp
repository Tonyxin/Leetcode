/*
����������
����n�������ļ���S����S��Ѱ��������a��b��c��ʹ��a+b+c=0��Ѱ�����еĲ��ظ���{a��b��c}����

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

���������
�ȶ�S���д�С��������򣬱���S����ÿһ��a����ʣ��ļ�����Ѱ��b��c��ʹ��b+c=target=0-a
ʹ������ָ��i��j���ֱ�ָ����βԪ�أ�
��S[i]+S[j]<target������S[i]==S[i-1]����i++;
��S[i]+S[j]>target������S[j]==S[j+1]����j--;
��S[i]+S[j]==target����i++��j--
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size()<3)
			return result;
		sort(nums.begin(), nums.end());
		auto itr_begin = nums.begin();
		auto itr_end = nums.end();
		for (auto itr1 = itr_begin; itr1 != itr_end - 2 && (*itr1) <= 0; itr1++)
		{
			if (itr1 != itr_begin&&*itr1 == *(itr1 - 1))
				continue;
			auto itr2 = itr1 + 1;
			auto itr3 = itr_end - 1;
			int target = 0 - (*itr1);
			int sum = (*itr2) + (*itr3);
			for (; itr2<itr3; sum = (*itr2) + (*itr3))
			{
				if (sum<target || (itr2 != itr1 + 1 && (*itr2) == (*(itr2 - 1))))  itr2++;
				else if (sum>target || (itr3 != itr_end - 1 && (*itr3) == (*(itr3 + 1))))  itr3--;
				else    result.push_back({ *itr1, *itr2++, *itr3-- });
			}
		}
		return result;
	}
};