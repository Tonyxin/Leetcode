/*
����������
������x[n]��Ԫ�ؾ�Ϊ����������Ŀ��ֵs����x��Ѱ����С�������У���sum>=s

���������
ѡȡ[i,j]��iȡ0��Ϊ��ʼ���ڣ�x[i]+...+x[j]>=s����֮�������ƶ����ڣ�j++����
���sum-x[i]>=s������i++����С���ڣ���¼ansֵ
*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())    return 0;
		int i = 0, j = 0;
		int sum = nums[i];
		while (sum<s)
		{
			if (j == nums.size() - 1)
				break;
			j++;
			sum += nums[j];
		}
		if (sum<s)   return 0;       //������������
		int ans = j - i + 1;              //��ʼ���ڣ�֮�󲻶���С
		while (1)
		{
			while (sum - nums[i] >= s)   //������С����
			{
				sum = sum - nums[i];
				i++;
			}
			if (j - i + 1<ans)           //����С�ڴ�
				ans = j - i + 1;
			if (j == nums.size() - 1)
				break;
			j++;
			sum = sum + nums[j];
		}
		return ans;
	}
};