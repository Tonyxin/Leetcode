/*
����������
��һ��������n��������2^n���������������ڶ�������ֻ����1λ��ͬ

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

���������
���õݹ�ķ�ʽ��
n=1					0
						1
n=2				  00				
					  01
					  11
					  10
n=3				000
					001
					011
					010
					110
					111
					101
					100
n+1����n�Ľ���ϣ����¶ԳƷ��ۣ�ǰһλ��1
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