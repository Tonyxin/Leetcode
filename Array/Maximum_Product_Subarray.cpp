/*
����������
��һ������������������Ԫ�ؿ����γ��Ӵ������Ӵ���Ԫ�س˻����ֵ

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

���������
������
���nums�в�����0�Ļ������ֵһ����������ڵ㣬�������ҽڵ�
      ͨ��һ�α������õ�������ڵ�����ֵ���Ͱ����ҽڵ�����ֵ���Ƚϼ�Ϊ��
���nums�к���0������0�����ã��൱�ڴ�һ���µ�nums����⣻
PS����Сֵ���󷨣��ڴ���ͬ��max��Ϊmin����
*/

class Solution {
public:
	//������
	//���nums�в�����0�Ļ������ֵһ����������ڵ㣬�������ҽڵ�
	//      ͨ��һ�α������õ�������ڵ�����ֵ���Ͱ����ҽڵ�����ֵ���Ƚϼ�Ϊ��
	//���nums�к���0������0�����ã��൱�ڴ�һ���µ�nums����⣻
	//PS����Сֵ���󷨣��ڴ���ͬ��max��Ϊmin����
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		if (!size)   return 0;
		int ans = INT_MIN;
		int front_product = 1;
		int back_product = 1;
		for (int i = 0; i<size; i++)
		{
			front_product = front_product*nums[i];
			back_product = back_product*nums[size - 1 - i];
			ans = max(ans, max(front_product, back_product));
			front_product = front_product == 0 ? 1 : front_product;
			back_product = back_product == 0 ? 1 : back_product;
		}
		return ans;
	}
};