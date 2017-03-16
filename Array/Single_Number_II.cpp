/*
问题描述：
给一列整数，由一个只出现1次，其他都出现3次，找到这个只出现一次的整数
要求：时间复杂度为O(n)，空间复杂度为O(1)

//想法：使用32个计数器，计量整数每一位1出现的次数，当出现3次计数器归0；
//      最终32个计数器的值（0或1）就是结果各位上的值
*/

class Solution {
public:
	//想法：使用32个计数器，计量整数每一位1出现的次数，当出现3次计数器归0；
	//      最终32个计数器的值（0或1）就是结果各位上的值
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