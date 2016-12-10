/*
����������
��һ���������������Ӵ��͵����ֵ
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
���������
�ڼ���һ����ǰ���ж�֮ǰԪ�غ��Ƿ�С��0����С��0��֮ǰ��ȫ��������
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int ans = nums[0];
		int sum = 0;
		for (const auto &c : nums)
		{
			if (sum<0)   sum = 0;      //�ڼ������֮ǰ���ȿ�֮ǰ�ĺ��Ƿ�С��0,��С���㣬֮ǰ��ȫ������
			sum += c;
			if (ans<sum) ans = sum;    //���ʼ��Ϊsum�����ֵ
		}
		return ans;
	}
};