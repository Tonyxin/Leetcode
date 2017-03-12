/*
����������
��n���������飬������㣬��ȥ������۳˽����Ҫ��ʱ�临�Ӷ�ΪO(n)
For example, given [1,2,3,4], return [24,12,8,6].

���������
���������������飬����(0,i-1)��ǰ���۳˺ͣ�i+1,size-1���ĺ����۳�
*/

class Solution {
public:
	//�뷨�����������������飬����(0,i-1)��ǰ���۳˺ͣ�i+1,size-1���ĺ����۳�
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans;
		int size = nums.size();
		if (!size)    return ans;
		vector<int> forward_multi(size, 1);
		vector<int> backward_multi(size, 1);
		//�õ������ǰ���۳�
		for (int i = 1; i<size; i++)
			forward_multi[i] = forward_multi[i - 1] * nums[i - 1];
		//�õ�����ĺ����۳�
		for (int i = size - 2; i >= 0; i--)
			backward_multi[i] = backward_multi[i + 1] * nums[i + 1];
		//�������ս��
		for (int i = 0; i<size; i++)
			ans.push_back(forward_multi[i] * backward_multi[i]);
		return ans;
	}
};