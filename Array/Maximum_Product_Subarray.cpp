/*
问题描述：
给一列整数，其中连续的元素可以形成子串，求子串各元素乘积最大值

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

解决方法：
分析：
如果nums中不包含0的话，最大值一定包含最左节点，或者最右节点
      通过一次遍历，得到包含左节点的最大值，和包含右节点的最大值，比较即为答案
如果nums中含有0，遇到0就重置，相当于从一段新的nums中求解；
PS：最小值的求法，于此相同，max改为min即可
*/

class Solution {
public:
	//分析：
	//如果nums中不包含0的话，最大值一定包含最左节点，或者最右节点
	//      通过一次遍历，得到包含左节点的最大值，和包含右节点的最大值，比较即为答案
	//如果nums中含有0，遇到0就重置，相当于从一段新的nums中求解；
	//PS：最小值的求法，于此相同，max改为min即可
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