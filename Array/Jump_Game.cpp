/*
����������
��һϵ�зǸ�������ʼ�ڵ�һ��λ�ã�ÿ��Ԫ�ش���������ߵ���󲽳�������ܷ��ߵ����

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

���������
����reach��ʾ��ǰ�ܹ��ߵ��������룬����[...reach]�������޸�reach��ֵ������Ƿ����ߵ����
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return false;
		int i = 0;
		//reach��ʾ��ǰ�ܹ��ߵ���������
		//����[...reach]�������޸�reach��ֵ
		//����Ƿ����ߵ����
		//�������ù�0������
		for (int reach = 0; i < n && i <= reach; ++i)
			reach = max(i + nums[i], reach);
		return i == n;
	}
};