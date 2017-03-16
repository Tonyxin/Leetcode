/*
����������
��һ����������һ��ֻ����1�Σ�����������3�Σ��ҵ����ֻ����һ�ε�����
Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)

//�뷨��ʹ��32������������������ÿһλ1���ֵĴ�����������3�μ�������0��
//      ����32����������ֵ��0��1�����ǽ����λ�ϵ�ֵ
*/

class Solution {
public:
	//�뷨��ʹ��32������������������ÿһλ1���ֵĴ�����������3�μ�������0��
	//      ����32����������ֵ��0��1�����ǽ����λ�ϵ�ֵ
	int singleNumber(vector<int>& nums) {
		int count[32];
		for (int i = 0; i<32; i++)
			count[i] = 0;
		for (const auto &c : nums)
		{
			for (int i = 0; i<32; i++)
			{
				if ((c >> i) & 1 == 1)
					count[i]++;
				if (count[i] == 3)
					count[i] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i<32; i++)
			ans += (count[i] << i);
		return ans;
	}
};