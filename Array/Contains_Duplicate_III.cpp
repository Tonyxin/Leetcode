/*
����������
����һ������nums���ж������Ƿ����������nums[i]��nums[j]
����|nums[i]-nums[j]|<=t��|i-j|<=k

���������
//�뷨������һ��������w����СΪk+1����w����������Ԫ�ؼ����������k��
//      �����ڵ�ֵ��multiset���棬�Ѿ��Զ������
//      ÿ��ѭ��ʱ
//          1��ȥ��ͷԪ�أ���������nums[i]
//          2��Ѱ��set���Ƿ����x��ʹ��|nums[i]-x|<=t;
//          3��|nums[i]-x|<=t,��x>=nums[i]-t����x<=nums[i]+t;
//          4������set�Ѿ���С����������ɣ�����Ѱ�ҵ�һ��x>=nums[i]-t�����x<=nums[i]+t����True
//      ע��int���͵�ȡֵ��Χ
*/
class Solution {
public:
	//�뷨������һ��������w����СΪk+1����w����������Ԫ�ؼ����������k��
	//      �����ڵ�ֵ��multiset���棬�Ѿ��Զ������
	//      ÿ��ѭ��ʱ
	//          1��ȥ��ͷԪ�أ���������nums[i]
	//          2��Ѱ��set���Ƿ����x��ʹ��|nums[i]-x|<=t;
	//          3��|nums[i]-x|<=t,��x>=nums[i]-t����x<=nums[i]+t;
	//          4������set�Ѿ���С����������ɣ�����Ѱ�ҵ�һ��x>=nums[i]-t�����x<=nums[i]+t����True
	//      ע��int���͵�ȡֵ��Χ
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int size = nums.size();
		if (size<2)  return false;
		multiset<int> window;
		for (int i = 0; i<size; i++)
		{
			if (i>k) window.erase(nums[i - k - 1]);
			auto itr = window.lower_bound((double)nums[i] - (double)t);
			if (itr != window.end() && (double)*itr <= (double)nums[i] + (double)t)
				return true;
			window.insert(nums[i]);
		}
		return false;
	}
};